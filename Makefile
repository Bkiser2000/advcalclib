# Cross-Platform Makefile for advcalclib
# Supports: Linux, Windows (MinGW/MSVC), macOS

# Detect OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    OS := LINUX
    CMAKE_GENERATOR := "Unix Makefiles"
    INSTALL_PREFIX := /usr/local
endif
ifeq ($(UNAME_S),Darwin)
    OS := MACOS
    CMAKE_GENERATOR := "Unix Makefiles"
    INSTALL_PREFIX := /usr/local
endif
ifeq ($(OS),)
    OS := WINDOWS
    CMAKE_GENERATOR := "MinGW Makefiles"
    INSTALL_PREFIX := C:\Program Files\advcalclib
endif

# Detect if using Windows
ifeq ($(OS_NAME),Windows_NT)
    OS := WINDOWS
    CMAKE_GENERATOR := "MinGW Makefiles"
    INSTALL_PREFIX := C:\Program Files\advcalclib
    RM := del /Q
    MKDIR := mkdir
    SEPARATOR := \
else
    RM := rm -rf
    MKDIR := mkdir -p
    SEPARATOR := /
endif

# Directories
BUILD_DIR := build
SOURCE_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests
EXAMPLE_DIR := examples
DIST_DIR := dist

# Build configuration
BUILD_TYPE ?= Release
CMAKE_FLAGS := -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

# Color output
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No Color

# Phony targets
.PHONY: all build install uninstall clean test help cmake_build upload_to_github

# Default target
all: help

# Help target
help:
    @echo "$(GREEN)Advanced Calculator Library - Cross-Platform Build System$(NC)"
    @echo ""
    @echo "Usage: make [target]"
    @echo ""
    @echo "Targets:"
    @echo "  $(YELLOW)build$(NC)              Build the library (default)"
    @echo "  $(YELLOW)install$(NC)            Build and install the library"
    @echo "  $(YELLOW)uninstall$(NC)          Uninstall the library"
    @echo "  $(YELLOW)test$(NC)               Build and run tests"
    @echo "  $(YELLOW)clean$(NC)              Remove build artifacts"
    @echo "  $(YELLOW)distclean$(NC)          Remove all generated files"
    @echo "  $(YELLOW)format$(NC)             Format source code (requires clang-format)"
    @echo "  $(YELLOW)lint$(NC)               Run static analysis (requires cppcheck)"
    @echo "  $(YELLOW)docs$(NC)               Generate documentation (requires Doxygen)"
    @echo "  $(YELLOW)package$(NC)            Create distribution package"
    @echo "  $(YELLOW)info$(NC)               Show build information"
    @echo ""
    @echo "Environment variables:"
    @echo "  $(YELLOW)BUILD_TYPE$(NC)         Build type (Debug/Release) - default: Release"
    @echo "  $(YELLOW)CMAKE_GENERATOR$(NC)    CMake generator to use"
    @echo ""

# Show build information
info:
    @echo "$(GREEN)Build Information$(NC)"
    @echo "Detected OS: $(OS)"
    @echo "CMake Generator: $(CMAKE_GENERATOR)"
    @echo "Build Type: $(BUILD_TYPE)"
    @echo "Install Prefix: $(INSTALL_PREFIX)"
    @echo "Build Directory: $(BUILD_DIR)"

# Configure with CMake
configure:
    @echo "$(GREEN)Configuring project...$(NC)"
    @if [ ! -d "$(BUILD_DIR)" ]; then $(MKDIR) $(BUILD_DIR); fi
    cd $(BUILD_DIR) && cmake .. -G $(CMAKE_GENERATOR) $(CMAKE_FLAGS) -DCMAKE_INSTALL_PREFIX=$(INSTALL_PREFIX)
    @echo "$(GREEN)Configuration complete$(NC)"

# Build the library
build: configure
    @echo "$(GREEN)Building advcalclib...$(NC)"
    cd $(BUILD_DIR) && cmake --build . --config $(BUILD_TYPE)
    @echo "$(GREEN)Build complete$(NC)"

# Install the library
install: build
    @echo "$(GREEN)Installing advcalclib...$(NC)"
ifeq ($(OS),WINDOWS)
    cd $(BUILD_DIR) && cmake --install . --prefix "$(INSTALL_PREFIX)"
else
    cd $(BUILD_DIR) && sudo cmake --install . --prefix $(INSTALL_PREFIX)
endif
    @echo "$(GREEN)Installation complete$(NC)"

# Uninstall the library
uninstall:
    @echo "$(RED)Uninstalling advcalclib...$(NC)"
ifeq ($(OS),WINDOWS)
    @echo "$(YELLOW)Manual uninstall required on Windows$(NC)"
    @echo "Remove from: $(INSTALL_PREFIX)"
else
    @sudo rm -f $(INSTALL_PREFIX)/lib/libadvcalclib*
    @sudo rm -f $(INSTALL_PREFIX)/include/calc.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/algebra.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/calculus.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/elec.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/fileio.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/geom.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/physics.hpp
    @sudo rm -f $(INSTALL_PREFIX)/include/utils.hpp
    @echo "$(GREEN)Uninstallation complete$(NC)"
endif

# Run tests
test: build
    @echo "$(GREEN)Running tests...$(NC)"
ifeq ($(OS),WINDOWS)
    cd $(BUILD_DIR) && ctest --output-on-failure --build-config $(BUILD_TYPE)
else
    cd $(BUILD_DIR) && ctest --output-on-failure
endif
    @echo "$(GREEN)Tests complete$(NC)"

# Clean build artifacts
clean:
    @echo "$(YELLOW)Cleaning build artifacts...$(NC)"
    $(RM) $(BUILD_DIR)
    @echo "$(GREEN)Clean complete$(NC)"

# Deep clean
distclean: clean
    @echo "$(YELLOW)Removing all generated files...$(NC)"
    $(RM) $(DIST_DIR)
    $(RM) *.o
ifeq ($(OS),WINDOWS)
    $(RM) *.dll
    $(RM) *.lib
else
    $(RM) *.so
    $(RM) *.a
endif
    @echo "$(GREEN)Distribution clean complete$(NC)"

# Format source code
format:
    @command -v clang-format >/dev/null 2>&1 || { echo "$(RED)clang-format not found$(NC)"; exit 1; }
    @echo "$(GREEN)Formatting source code...$(NC)"
    @find $(SOURCE_DIR) -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i
    @find $(INCLUDE_DIR) -name "*.hpp" | xargs clang-format -i
    @echo "$(GREEN)Formatting complete$(NC)"

# Static analysis
lint:
    @command -v cppcheck >/dev/null 2>&1 || { echo "$(RED)cppcheck not found$(NC)"; exit 1; }
    @echo "$(GREEN)Running static analysis...$(NC)"
    @cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCE_DIR) $(INCLUDE_DIR)
    @echo "$(GREEN)Analysis complete$(NC)"

# Generate documentation
docs:
    @command -v doxygen >/dev/null 2>&1 || { echo "$(RED)Doxygen not found$(NC)"; exit 1; }
    @echo "$(GREEN)Generating documentation...$(NC)"
    @doxygen Doxyfile
    @echo "$(GREEN)Documentation generated in docs/$(NC)"

# Create distribution package
package: distclean
    @echo "$(GREEN)Creating distribution package...$(NC)"
    @$(MKDIR) $(DIST_DIR)
ifeq ($(OS),WINDOWS)
    @xcopy $(SOURCE_DIR) $(DIST_DIR)$(SEPARATOR)$(SOURCE_DIR) /E
    @xcopy $(INCLUDE_DIR) $(DIST_DIR)$(SEPARATOR)$(INCLUDE_DIR) /E
    @copy CMakeLists.txt $(DIST_DIR)
    @copy README.md $(DIST_DIR)
    @copy LICENSE $(DIST_DIR)
    @cd $(DIST_DIR) && tar -czf advcalclib-package.tar.gz .
else
    @cp -r $(SOURCE_DIR) $(DIST_DIR)/
    @cp -r $(INCLUDE_DIR) $(DIST_DIR)/
    @cp CMakeLists.txt $(DIST_DIR)/
    @cp README.md $(DIST_DIR)/
    @cp LICENSE $(DIST_DIR)/
    @cp Makefile $(DIST_DIR)/
    @cd $(DIST_DIR) && tar -czf advcalclib-package.tar.gz . && cd ..
    @echo "$(GREEN)Package created: $(DIST_DIR)/advcalclib-package.tar.gz$(NC)"
endif

# Rebuild from scratch
rebuild: distclean build
    @echo "$(GREEN)Rebuild complete$(NC)"

# Development setup
dev-setup: configure
    @echo "$(GREEN)Setting up development environment...$(NC)"
    @echo "Build directory: $(BUILD_DIR)"
    @echo "Ready for development"

# Run example
run-example: build
    @echo "$(GREEN)Running example...$(NC)"
ifeq ($(OS),WINDOWS)
    cd $(BUILD_DIR) && exam.exe
else
    cd $(BUILD_DIR) && ./exam
endif

# Check dependencies
check-deps:
    @echo "$(GREEN)Checking dependencies...$(NC)"
    @command -v cmake >/dev/null 2>&1 && echo "✓ CMake found" || echo "✗ CMake not found"
    @command -v g++ >/dev/null 2>&1 && echo "✓ G++ found" || echo "✗ G++ not found"
    @command -v clang-format >/dev/null 2>&1 && echo "✓ clang-format found" || echo "✗ clang-format not found"
    @command -v cppcheck >/dev/null 2>&1 && echo "✓ cppcheck found" || echo "✗ cppcheck not found"
    @command -v doxygen >/dev/null 2>&1 && echo "✓ Doxygen found" || echo "✗ Doxygen not found"

# Git workflow targets
git-commit-staged:
    @echo "$(GREEN)Committing staged changes...$(NC)"
    git commit -m "Build: automated commit from make"

git-push:
    @echo "$(GREEN)Pushing to remote...$(NC)"
    git push origin main

# Install development tools
install-dev-tools:
    @echo "$(GREEN)Installing development tools...$(NC)"
ifeq ($(OS),LINUX)
    @sudo apt-get install -y cmake build-essential clang-format cppcheck doxygen
else ifeq ($(OS),MACOS)
    @brew install cmake clang-format cppcheck doxygen
else
    @echo "$(YELLOW)Manual installation required on Windows$(NC)"
endif
    @echo "$(GREEN)Installation complete$(NC)"

# Verbose build
build-verbose: configure
    @echo "$(GREEN)Building with verbose output...$(NC)"
    cd $(BUILD_DIR) && cmake --build . --config $(BUILD_TYPE) --verbose

# Display size of library
size: build
    @echo "$(GREEN)Library size:$(NC)"
ifeq ($(OS),WINDOWS)
    @powershell -Command "Get-Item $(BUILD_DIR) | Select-Object Length"
else
    @du -sh $(BUILD_DIR)
endif

# Quick test and install
quick-install: build test install
    @echo "$(GREEN)Quick install complete$(NC)"

# View build log
view-log:
    @if [ -f "$(BUILD_DIR)/CMakeOutput.log" ]; then cat $(BUILD_DIR)/CMakeOutput.log; else echo "No log file found"; fi

.PHONY: all build install uninstall test clean distclean format lint docs package rebuild dev-setup run-example check-deps git-commit-staged git-push install-dev-tools build-verbose size quick-install view-log info configure
