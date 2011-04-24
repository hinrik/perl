/* -*- buffer-read-only: t -*-
 *
 *    opnames.h
 *
 *    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
 *    2008 by Larry Wall and others
 *
 *    You may distribute under the terms of either the GNU General Public
 *    License or the Artistic License, as specified in the README file.
 *
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 * This file is built by regen/opcode.pl from its data.
 * Any changes made here will be lost!
 */

typedef enum opcode {
	OP_NULL		 = 0,
	OP_STUB		 = 1,
	OP_SCALAR	 = 2,
	OP_PUSHMARK	 = 3,
	OP_WANTARRAY	 = 4,
	OP_CONST	 = 5,
	OP_GVSV		 = 6,
	OP_GV		 = 7,
	OP_GELEM	 = 8,
	OP_PADSV	 = 9,
	OP_PADAV	 = 10,
	OP_PADHV	 = 11,
	OP_PADANY	 = 12,
	OP_PUSHRE	 = 13,
	OP_RV2GV	 = 14,
	OP_RV2SV	 = 15,
	OP_AV2ARYLEN	 = 16,
	OP_RV2CV	 = 17,
	OP_ANONCODE	 = 18,
	OP_PROTOTYPE	 = 19,
	OP_REFGEN	 = 20,
	OP_SREFGEN	 = 21,
	OP_REF		 = 22,
	OP_BLESS	 = 23,
	OP_BACKTICK	 = 24,
	OP_GLOB		 = 25,
	OP_READLINE	 = 26,
	OP_RCATLINE	 = 27,
	OP_REGCMAYBE	 = 28,
	OP_REGCRESET	 = 29,
	OP_REGCOMP	 = 30,
	OP_MATCH	 = 31,
	OP_QR		 = 32,
	OP_SUBST	 = 33,
	OP_SUBSTCONT	 = 34,
	OP_TRANS	 = 35,
	OP_SASSIGN	 = 36,
	OP_AASSIGN	 = 37,
	OP_CHOP		 = 38,
	OP_SCHOP	 = 39,
	OP_CHOMP	 = 40,
	OP_SCHOMP	 = 41,
	OP_DEFINED	 = 42,
	OP_UNDEF	 = 43,
	OP_STUDY	 = 44,
	OP_POS		 = 45,
	OP_PREINC	 = 46,
	OP_I_PREINC	 = 47,
	OP_PREDEC	 = 48,
	OP_I_PREDEC	 = 49,
	OP_POSTINC	 = 50,
	OP_I_POSTINC	 = 51,
	OP_POSTDEC	 = 52,
	OP_I_POSTDEC	 = 53,
	OP_POW		 = 54,
	OP_MULTIPLY	 = 55,
	OP_I_MULTIPLY	 = 56,
	OP_DIVIDE	 = 57,
	OP_I_DIVIDE	 = 58,
	OP_MODULO	 = 59,
	OP_I_MODULO	 = 60,
	OP_REPEAT	 = 61,
	OP_ADD		 = 62,
	OP_I_ADD	 = 63,
	OP_SUBTRACT	 = 64,
	OP_I_SUBTRACT	 = 65,
	OP_CONCAT	 = 66,
	OP_STRINGIFY	 = 67,
	OP_LEFT_SHIFT	 = 68,
	OP_RIGHT_SHIFT	 = 69,
	OP_LT		 = 70,
	OP_I_LT		 = 71,
	OP_GT		 = 72,
	OP_I_GT		 = 73,
	OP_LE		 = 74,
	OP_I_LE		 = 75,
	OP_GE		 = 76,
	OP_I_GE		 = 77,
	OP_EQ		 = 78,
	OP_I_EQ		 = 79,
	OP_NE		 = 80,
	OP_I_NE		 = 81,
	OP_NCMP		 = 82,
	OP_I_NCMP	 = 83,
	OP_SLT		 = 84,
	OP_SGT		 = 85,
	OP_SLE		 = 86,
	OP_SGE		 = 87,
	OP_SEQ		 = 88,
	OP_SNE		 = 89,
	OP_SCMP		 = 90,
	OP_BIT_AND	 = 91,
	OP_BIT_XOR	 = 92,
	OP_BIT_OR	 = 93,
	OP_NEGATE	 = 94,
	OP_I_NEGATE	 = 95,
	OP_NOT		 = 96,
	OP_COMPLEMENT	 = 97,
	OP_SMARTMATCH	 = 98,
	OP_ATAN2	 = 99,
	OP_SIN		 = 100,
	OP_COS		 = 101,
	OP_RAND		 = 102,
	OP_SRAND	 = 103,
	OP_EXP		 = 104,
	OP_LOG		 = 105,
	OP_SQRT		 = 106,
	OP_INT		 = 107,
	OP_HEX		 = 108,
	OP_OCT		 = 109,
	OP_ABS		 = 110,
	OP_LENGTH	 = 111,
	OP_SUBSTR	 = 112,
	OP_VEC		 = 113,
	OP_INDEX	 = 114,
	OP_RINDEX	 = 115,
	OP_SPRINTF	 = 116,
	OP_FORMLINE	 = 117,
	OP_ORD		 = 118,
	OP_CHR		 = 119,
	OP_CRYPT	 = 120,
	OP_UCFIRST	 = 121,
	OP_LCFIRST	 = 122,
	OP_UC		 = 123,
	OP_LC		 = 124,
	OP_QUOTEMETA	 = 125,
	OP_RV2AV	 = 126,
	OP_AELEMFAST	 = 127,
	OP_AELEMFAST_LEX = 128,
	OP_AELEM	 = 129,
	OP_ASLICE	 = 130,
	OP_AEACH	 = 131,
	OP_AKEYS	 = 132,
	OP_AVALUES	 = 133,
	OP_EACH		 = 134,
	OP_VALUES	 = 135,
	OP_KEYS		 = 136,
	OP_DELETE	 = 137,
	OP_EXISTS	 = 138,
	OP_RV2HV	 = 139,
	OP_HELEM	 = 140,
	OP_HSLICE	 = 141,
	OP_BOOLKEYS	 = 142,
	OP_UNPACK	 = 143,
	OP_PACK		 = 144,
	OP_SPLIT	 = 145,
	OP_JOIN		 = 146,
	OP_LIST		 = 147,
	OP_LSLICE	 = 148,
	OP_ANONLIST	 = 149,
	OP_ANONHASH	 = 150,
	OP_SPLICE	 = 151,
	OP_PUSH		 = 152,
	OP_POP		 = 153,
	OP_SHIFT	 = 154,
	OP_UNSHIFT	 = 155,
	OP_SORT		 = 156,
	OP_REVERSE	 = 157,
	OP_GREPSTART	 = 158,
	OP_GREPWHILE	 = 159,
	OP_MAPSTART	 = 160,
	OP_MAPWHILE	 = 161,
	OP_RANGE	 = 162,
	OP_FLIP		 = 163,
	OP_FLOP		 = 164,
	OP_AND		 = 165,
	OP_OR		 = 166,
	OP_XOR		 = 167,
	OP_DOR		 = 168,
	OP_COND_EXPR	 = 169,
	OP_ANDASSIGN	 = 170,
	OP_ORASSIGN	 = 171,
	OP_DORASSIGN	 = 172,
	OP_METHOD	 = 173,
	OP_ENTERSUB	 = 174,
	OP_LEAVESUB	 = 175,
	OP_LEAVESUBLV	 = 176,
	OP_CALLER	 = 177,
	OP_WARN		 = 178,
	OP_DIE		 = 179,
	OP_RESET	 = 180,
	OP_LINESEQ	 = 181,
	OP_NEXTSTATE	 = 182,
	OP_DBSTATE	 = 183,
	OP_UNSTACK	 = 184,
	OP_ENTER	 = 185,
	OP_LEAVE	 = 186,
	OP_SCOPE	 = 187,
	OP_ENTERITER	 = 188,
	OP_ITER		 = 189,
	OP_ENTERLOOP	 = 190,
	OP_LEAVELOOP	 = 191,
	OP_RETURN	 = 192,
	OP_LAST		 = 193,
	OP_NEXT		 = 194,
	OP_REDO		 = 195,
	OP_DUMP		 = 196,
	OP_GOTO		 = 197,
	OP_EXIT		 = 198,
	OP_METHOD_NAMED	 = 199,
	OP_ENTERGIVEN	 = 200,
	OP_LEAVEGIVEN	 = 201,
	OP_ENTERWHEN	 = 202,
	OP_LEAVEWHEN	 = 203,
	OP_BREAK	 = 204,
	OP_CONTINUE	 = 205,
	OP_OPEN		 = 206,
	OP_CLOSE	 = 207,
	OP_PIPE_OP	 = 208,
	OP_FILENO	 = 209,
	OP_UMASK	 = 210,
	OP_BINMODE	 = 211,
	OP_TIE		 = 212,
	OP_UNTIE	 = 213,
	OP_TIED		 = 214,
	OP_DBMOPEN	 = 215,
	OP_DBMCLOSE	 = 216,
	OP_SSELECT	 = 217,
	OP_SELECT	 = 218,
	OP_GETC		 = 219,
	OP_READ		 = 220,
	OP_ENTERWRITE	 = 221,
	OP_LEAVEWRITE	 = 222,
	OP_PRTF		 = 223,
	OP_PRINT	 = 224,
	OP_SAY		 = 225,
	OP_SYSOPEN	 = 226,
	OP_SYSSEEK	 = 227,
	OP_SYSREAD	 = 228,
	OP_SYSWRITE	 = 229,
	OP_EOF		 = 230,
	OP_TELL		 = 231,
	OP_SEEK		 = 232,
	OP_TRUNCATE	 = 233,
	OP_FCNTL	 = 234,
	OP_IOCTL	 = 235,
	OP_FLOCK	 = 236,
	OP_SEND		 = 237,
	OP_RECV		 = 238,
	OP_SOCKET	 = 239,
	OP_SOCKPAIR	 = 240,
	OP_BIND		 = 241,
	OP_CONNECT	 = 242,
	OP_LISTEN	 = 243,
	OP_ACCEPT	 = 244,
	OP_SHUTDOWN	 = 245,
	OP_GSOCKOPT	 = 246,
	OP_SSOCKOPT	 = 247,
	OP_GETSOCKNAME	 = 248,
	OP_GETPEERNAME	 = 249,
	OP_LSTAT	 = 250,
	OP_STAT		 = 251,
	OP_FTRREAD	 = 252,
	OP_FTRWRITE	 = 253,
	OP_FTREXEC	 = 254,
	OP_FTEREAD	 = 255,
	OP_FTEWRITE	 = 256,
	OP_FTEEXEC	 = 257,
	OP_FTIS		 = 258,
	OP_FTSIZE	 = 259,
	OP_FTMTIME	 = 260,
	OP_FTATIME	 = 261,
	OP_FTCTIME	 = 262,
	OP_FTROWNED	 = 263,
	OP_FTEOWNED	 = 264,
	OP_FTZERO	 = 265,
	OP_FTSOCK	 = 266,
	OP_FTCHR	 = 267,
	OP_FTBLK	 = 268,
	OP_FTFILE	 = 269,
	OP_FTDIR	 = 270,
	OP_FTPIPE	 = 271,
	OP_FTSUID	 = 272,
	OP_FTSGID	 = 273,
	OP_FTSVTX	 = 274,
	OP_FTLINK	 = 275,
	OP_FTTTY	 = 276,
	OP_FTTEXT	 = 277,
	OP_FTBINARY	 = 278,
	OP_CHDIR	 = 279,
	OP_CHOWN	 = 280,
	OP_CHROOT	 = 281,
	OP_UNLINK	 = 282,
	OP_CHMOD	 = 283,
	OP_UTIME	 = 284,
	OP_RENAME	 = 285,
	OP_LINK		 = 286,
	OP_SYMLINK	 = 287,
	OP_READLINK	 = 288,
	OP_MKDIR	 = 289,
	OP_RMDIR	 = 290,
	OP_OPEN_DIR	 = 291,
	OP_READDIR	 = 292,
	OP_TELLDIR	 = 293,
	OP_SEEKDIR	 = 294,
	OP_REWINDDIR	 = 295,
	OP_CLOSEDIR	 = 296,
	OP_FORK		 = 297,
	OP_WAIT		 = 298,
	OP_WAITPID	 = 299,
	OP_SYSTEM	 = 300,
	OP_EXEC		 = 301,
	OP_KILL		 = 302,
	OP_GETPPID	 = 303,
	OP_GETPGRP	 = 304,
	OP_SETPGRP	 = 305,
	OP_GETPRIORITY	 = 306,
	OP_SETPRIORITY	 = 307,
	OP_TIME		 = 308,
	OP_TMS		 = 309,
	OP_LOCALTIME	 = 310,
	OP_GMTIME	 = 311,
	OP_ALARM	 = 312,
	OP_SLEEP	 = 313,
	OP_SHMGET	 = 314,
	OP_SHMCTL	 = 315,
	OP_SHMREAD	 = 316,
	OP_SHMWRITE	 = 317,
	OP_MSGGET	 = 318,
	OP_MSGCTL	 = 319,
	OP_MSGSND	 = 320,
	OP_MSGRCV	 = 321,
	OP_SEMOP	 = 322,
	OP_SEMGET	 = 323,
	OP_SEMCTL	 = 324,
	OP_REQUIRE	 = 325,
	OP_DOFILE	 = 326,
	OP_HINTSEVAL	 = 327,
	OP_ENTEREVAL	 = 328,
	OP_LEAVEEVAL	 = 329,
	OP_ENTERTRY	 = 330,
	OP_LEAVETRY	 = 331,
	OP_GHBYNAME	 = 332,
	OP_GHBYADDR	 = 333,
	OP_GHOSTENT	 = 334,
	OP_GNBYNAME	 = 335,
	OP_GNBYADDR	 = 336,
	OP_GNETENT	 = 337,
	OP_GPBYNAME	 = 338,
	OP_GPBYNUMBER	 = 339,
	OP_GPROTOENT	 = 340,
	OP_GSBYNAME	 = 341,
	OP_GSBYPORT	 = 342,
	OP_GSERVENT	 = 343,
	OP_SHOSTENT	 = 344,
	OP_SNETENT	 = 345,
	OP_SPROTOENT	 = 346,
	OP_SSERVENT	 = 347,
	OP_EHOSTENT	 = 348,
	OP_ENETENT	 = 349,
	OP_EPROTOENT	 = 350,
	OP_ESERVENT	 = 351,
	OP_GPWNAM	 = 352,
	OP_GPWUID	 = 353,
	OP_GPWENT	 = 354,
	OP_SPWENT	 = 355,
	OP_EPWENT	 = 356,
	OP_GGRNAM	 = 357,
	OP_GGRGID	 = 358,
	OP_GGRENT	 = 359,
	OP_SGRENT	 = 360,
	OP_EGRENT	 = 361,
	OP_GETLOGIN	 = 362,
	OP_SYSCALL	 = 363,
	OP_LOCK		 = 364,
	OP_ONCE		 = 365,
	OP_CUSTOM	 = 366,
	OP_REACH	 = 367,
	OP_RKEYS	 = 368,
	OP_RVALUES	 = 369,
	OP_TRANSR	 = 370,
	OP_max		
} opcode;

#define MAXO 371

/* the OP_IS_(SOCKET|FILETEST) macros are optimized to a simple range
    check because all the member OPs are contiguous in opcode.pl
    <OPS> table.  opcode.pl verifies the range contiguity.  */

#define OP_IS_SOCKET(op)	\
	((op) >= OP_SEND && (op) <= OP_GETPEERNAME)

#define OP_IS_FILETEST(op)	\
	((op) >= OP_FTRREAD && (op) <= OP_FTBINARY)

#define OP_IS_FILETEST_ACCESS(op)	\
	((op) >= OP_FTRREAD && (op) <= OP_FTEEXEC)

/* ex: set ro: */
