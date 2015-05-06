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
CND_PLATFORM=GNU-Linux-x86
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
	${OBJECTDIR}/_ext/1338900640/Stats.o \
	${OBJECTDIR}/_ext/1338900640/main.o \
	${OBJECTDIR}/_ext/1338900640/matrix.o \
	${OBJECTDIR}/_ext/1338900640/poly.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linux-least-squares

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linux-least-squares: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linux-least-squares ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1338900640/Stats.o: ../linear-least-squares/linear-least-squares/Stats.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1338900640
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1338900640/Stats.o ../linear-least-squares/linear-least-squares/Stats.cpp

${OBJECTDIR}/_ext/1338900640/main.o: ../linear-least-squares/linear-least-squares/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1338900640
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1338900640/main.o ../linear-least-squares/linear-least-squares/main.cpp

${OBJECTDIR}/_ext/1338900640/matrix.o: ../linear-least-squares/linear-least-squares/matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1338900640
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1338900640/matrix.o ../linear-least-squares/linear-least-squares/matrix.cpp

${OBJECTDIR}/_ext/1338900640/poly.o: ../linear-least-squares/linear-least-squares/poly.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1338900640
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1338900640/poly.o ../linear-least-squares/linear-least-squares/poly.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/linux-least-squares

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
