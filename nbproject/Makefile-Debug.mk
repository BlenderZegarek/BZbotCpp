#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/commands/pfp.o \
	${OBJECTDIR}/commands/ping.o \
	${OBJECTDIR}/commands/simple-embed.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/utils/utils.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs Magick++`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk bzbotcpp

bzbotcpp: ${OBJECTFILES}
	${LINK.cc} -o bzbotcpp ${OBJECTFILES} ${LDLIBSOPTIONS} -ldpp -ljsoncpp

${OBJECTDIR}/commands/pfp.o: commands/pfp.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/commands
	${RM} "$@.d"
	$(COMPILE.cc) -g -Icommands -Iutils `pkg-config --cflags Magick++` -std=c++17  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/commands/pfp.o commands/pfp.cpp

${OBJECTDIR}/commands/ping.o: commands/ping.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/commands
	${RM} "$@.d"
	$(COMPILE.cc) -g -Icommands -Iutils `pkg-config --cflags Magick++` -std=c++17  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/commands/ping.o commands/ping.cpp

${OBJECTDIR}/commands/simple-embed.o: commands/simple-embed.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/commands
	${RM} "$@.d"
	$(COMPILE.cc) -g -Icommands -Iutils `pkg-config --cflags Magick++` -std=c++17  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/commands/simple-embed.o commands/simple-embed.cpp

${OBJECTDIR}/main.o: main.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Icommands -Iutils `pkg-config --cflags Magick++` -std=c++17  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/utils/utils.o: utils/utils.cpp nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -Icommands -Iutils `pkg-config --cflags Magick++` -std=c++17  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/utils.o utils/utils.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
