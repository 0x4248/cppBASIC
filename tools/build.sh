#!/bin/bash
# cppBASIC
# A simple BASIC like interpreter in C++
# Github: https://www.github.com/0x4248/cppBASIC
# Licence: GNU General Public License v3.0
# By: 0x4248

CXX=g++

SRC_DIR=src
INC_DIR=include
BUILD_DIR=bin

SRC_FILES=$(find ${SRC_DIR} -name "*.cpp")
OBJ_FILES=$(echo "${SRC_FILES}" | sed "s|${SRC_DIR}/|${BUILD_DIR}/|g;s|.cpp|.o|g")
INC_FLAGS="-I${INC_DIR}"

CXXFLAGS="-Wall -Wextra -pedantic -std=c++11"

TARGET=cppBASIC

init() {
    mkdir -p ${BUILD_DIR}
}

build() {
    for file in ${SRC_FILES}; do
        obj_file="${BUILD_DIR}/${file#${SRC_DIR}/}"
        obj_file="${obj_file%.cpp}.o"
        mkdir -p "$(dirname "${obj_file}")"
        ${CXX} ${CXXFLAGS} ${INC_FLAGS} -c ${file} -o ${obj_file}
    done
    ${CXX} ${CXXFLAGS} ${INC_FLAGS} $(find ${BUILD_DIR} -name "*.o") -o ${BUILD_DIR}/${TARGET}
}

init
build
