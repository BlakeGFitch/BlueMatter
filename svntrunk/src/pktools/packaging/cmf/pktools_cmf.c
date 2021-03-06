/* Copyright 2001, 2019 IBM Corporation
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the 
 * following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
 * following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 #define QUOTE(s2) #s2
#define STRING(s) QUOTE(s)
#define APPEND(value1,value2) value1 ## value2
#define MKPATH(path,filename) APPEND(path,filename)
#define ADDEXT(filename,extension) APPEND(filename, extension)

#define MODE "755"
#define EXEC_MODE "555"
#define READ_MODE "444"
#define RW_MODE "666"
#define SU_EXEC_MODE "4555"


  #define VERSION    '0'
  #define RELEASE    '0'
  #define MAINTLEVEL '0203'
  #define FIXLEVEL   '20'

  #define COPYRIGHT "Copyright IBM, 2001, 2002"

	#define BOOTRQMT 'No'
	#define FILE 'F'
	#define DIR 'D'
	#define LINK 'S'
	#define INSTALLDIR /usr/opt/bluegene

    #define bin_user STRING(2)

    #define PACKAGE_ENTITY_NAME "bluegene.pktools"
    #define PACKAGE_FULL_ENTITY_NAME PACKAGE_ENTITY_NAME

	#define SRC_ENTITY_NAME  "bluegene.pktools.src"
	#define SRC_FULL_ENTITY_NAME SRC_ENTITY_NAME

	#define RTE_ENTITY_NAME  "bluegene.pktools.rte"
	#define RTE_FULL_ENTITY_NAME RTE_ENTITY_NAME

    #define NIBM_ENTITY_NAME  "bluegene.pktools.nibm"
    #define NIBM_FULL_ENTITY_NAME  NIBM_ENTITY_NAME

    #define NR_ENTITY_NAME  "bluegene.pktools.nr"
    #define NR_FULL_ENTITY_NAME  NR_ENTITY_NAME






#if defined(rios_aix_5) || defined(rios_aix_4)
  /* AIX specific settings */

  #define LIBEXT .a
  #define DYNLOADOBJEXT .so

  #define root     STRING(0)
  #define system   STRING(0)
  /* Can't have just 'bin' - would screw up path names */
  /* #define bin_user STRING(2) */

#endif

  #define INSTALLSRC  INSTALLDIR/
  #define BINSRC      INSTALLDIR/bin/
  #define INCSRC      INSTALLDIR/include/
  #define SRCSRC      INSTALLDIR/src/
  #define LIBSRC      INSTALLDIR/lib/
  #define SAMPSRC     INSTALLDIR/sample/
  #define DOCSRC      INSTALLDIR/html/

#define BINTGT   BINSRC
#define INCTGT   INCSRC
#define SRCTGT   SRCSRC
#define LIBTGT   LIBSRC
#define SAMPTGT  SAMPSRC
#define DOCTGT   DOCSRC

#include <cmf/pktools.entity>
#include <cmf/pktools_rte.entity>
#include <cmf/pktools_src.entity>
#include <cmf/pktools_nibm.entity>
#include <cmf/pktools_nr.entity>
#define PACKAGE_FILE(directory, filename)        \
file                                             \
{                                                 \
                                                   \
  partNum = PARTNUM;                                 \
  fileType = FILE;                               \
  sourceFile = STRING(filename);                 \
  targetFile = STRING(filename);                 \
  sourceDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  targetDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  permissions = READ_MODE;                       \
  userId = bin_user;                             \
  groupId = bin_user;                            \
}

#define PACKAGE_FILE_EXEC(directory, filename)        \
file                                             \
{                                                 \
                                                   \
  partNum = PARTNUM;                                 \
  fileType = FILE;                               \
  sourceFile = STRING(filename);                 \
  targetFile = STRING(filename);                 \
  sourceDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  targetDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  permissions = EXEC_MODE;                       \
  userId = bin_user;                             \
  groupId = bin_user;                            \
}

#define PACKAGE_FILE_SETUID(directory, filename)        \
file                                             \
{                                                 \
                                                   \
  partNum = PARTNUM;                                 \
  fileType = FILE;                               \
  sourceFile = STRING(filename);                 \
  targetFile = STRING(filename);                 \
  sourceDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  targetDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  permissions = SU_EXEC_MODE;                       \
  userId = root;                             \
  groupId = bin_user;                            \
}

#define PACKAGE_DIRECTORY(directory)             \
file                                             \
{                                                \
                                                   \
  partNum = PARTNUM;                                 \
  fileType = DIR;                                \
  sourceDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  targetDir  = STRING(MKPATH(INSTALLSRC,directory)); \
  permissions = EXEC_MODE;                       \
  userId = bin_user;                             \
  groupId = bin_user;                            \
}
#define PARTNUM '1'
#include <cmf/pktools_rte.files>
#undef PARTNUM
#define PARTNUM '1'
#include <cmf/pktools_src.files>
#undef PARTNUM
#define PARTNUM '1'
#include <cmf/pktools_nibm.files>
#undef PARTNUM
#define PARTNUM '1'
#include <cmf/pktools_nr.files>
#undef PARTNUM
#undef PACKAGE_FILE
#undef PACKAGE_FILE_EXEC
#undef PACKAGE_FILE_SETUID
#undef PACKAGE_DIRECTORY

