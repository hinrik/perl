#!/usr/bin/perl -w

# This is a test checking various aspects of the optional argument
# MIN_PERL_VERSION to WriteMakefile.

BEGIN {
    unshift @INC, 't/lib';
}

use strict;
use Test::More tests => 18;

use TieOut;
use MakeMaker::Test::Utils;
use MakeMaker::Test::Setup::SAS;
use File::Path;

use ExtUtils::MakeMaker;

# avoid environment variables interfering with our make runs
delete @ENV{qw(LIB MAKEFLAGS)};

my $perl     = which_perl();
my $make     = make_run();
my $makefile = makefile_name();

chdir 't';

perl_lib();

ok( setup_recurs(), 'setup' );
END {
    ok( chdir(File::Spec->updir), 'leaving dir' );
    ok( teardown_recurs(), 'teardown' );
}

ok( chdir $MakeMaker::Test::Setup::SAS::dirname, "entering dir $MakeMaker::Test::Setup::SAS::dirname" ) ||
    diag("chdir failed: $!");

{
    # ----- argument verification -----

    my $stdout = tie *STDOUT, 'TieOut';
    ok( $stdout, 'capturing stdout' );
    my $warnings = '';
    local $SIG{__WARN__} = sub {
        $warnings .= join '', @_;
    };

    eval {
        WriteMakefile(
            NAME             => 'Multiple::Authors',
            AUTHOR           => ['John Doe <jd@example.com>', 'Jane Doe <jd@example.com>'],
        );
    };
    is( $warnings, '', 'arrayref in AUTHOR does not trigger a warning' );
    is( $@, '',        '  nor a hard failure' );

}


{
    # ----- argument verification -----

    my $stdout = tie *STDOUT, 'TieOut';
    ok( $stdout, 'capturing stdout' );
    my $warnings = '';
    local $SIG{__WARN__} = sub {
        $warnings .= join '', @_;
    };

    eval {
        WriteMakefile(
            NAME             => 'Multiple::Authors',
            CONFIGURE => sub { 
               return {AUTHOR => 'John Doe <jd@example.com>',};
            },
        );
    };
    is( $warnings, '', 'scalar in AUTHOR inside CONFIGURE does not trigger a warning' );
    is( $@, '',        '  nor a hard failure' );

}


# ----- generated files verification -----
{
    unlink $makefile;
    my @mpl_out = run(qq{$perl Makefile.PL});
    END { unlink $makefile, makefile_backup() }

    cmp_ok( $?, '==', 0, 'Makefile.PL exiting normally' ) || diag(@mpl_out);
    ok( -e $makefile, 'Makefile present' );
}


# ----- ppd output -----
{
    my $ppd_file = 'Multiple-Authors.ppd';
    my @make_out = run(qq{$make ppd});
    END { unlink $ppd_file }

    cmp_ok( $?, '==', 0,    'Make ppd exiting normally' ) || diag(@make_out);

    my $ppd_html = slurp($ppd_file);
    ok( defined($ppd_html), '  .ppd file present' );

    like( $ppd_html, qr{John Doe &lt;jd\@example.com&gt;, Jane Doe &lt;jd\@example.com&gt;},
                            '  .ppd file content good' );
}


# ----- META.yml output -----
{
    my $distdir  = 'Multiple-Authors-0.05';
    $distdir =~ s{\.}{_}g if $Is_VMS;

    my $meta_yml = "$distdir/META.yml";
    my @make_out    = run(qq{$make metafile});
    END { rmtree $distdir }

    cmp_ok( $?, '==', 0, 'Make metafile exiting normally' ) || diag(@make_out);
    my $meta = slurp($meta_yml);
    ok( defined($meta),  '  META.yml present' );

    like( $meta, qr{\nauthor:\n\s+- John Doe <jd\@example.com>\n\s+- Jane Doe <jd\@example.com>\n},
                         '  META.yml content good');
}

__END__
