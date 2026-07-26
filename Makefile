COMPILER = g++
BUILD_DIR = build
TARGET = ${BUILD_DIR}/hopcat

${TARGET}: src/main.cpp src/docker_client.cpp src/podman_client.cpp
	mkdir -p ${BUILD_DIR}
	${COMPILER} $^ -o $@