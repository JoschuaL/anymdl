#*****************************************************************************
# Copyright (c) 2018-2020, NVIDIA CORPORATION. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#  * Neither the name of NVIDIA CORPORATION nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#*****************************************************************************

# -------------------------------------------------------------------------------------------------
# script expects the following variables:
# - __TARGET_ADD_DEPENDENCY_TARGET
# - __TARGET_ADD_DEPENDENCY_DEPENDS
# - __TARGET_ADD_DEPENDENCY_COMPONENTS
# - __TARGET_ADD_DEPENDENCY_NO_RUNTIME_COPY
# - __TARGET_ADD_DEPENDENCY_NO_LINKING
# -------------------------------------------------------------------------------------------------

# assuming we can use a non-modified version some day

# up till then we add a build dependency here
# add includes link dependencies

# list of llvm Libraries we need
set(_LLVM_LIB_NAMES 
    LLVMLinker
    LLVMipo
    LLVMVectorize
    LLVMBitWriter
    LLVMNVPTXCodeGen
    LLVMNVPTXDesc
    LLVMNVPTXInfo
    LLVMNVPTXAsmPrinter
    LLVMTableGen
    LLVMDebugInfoDWARF
    LLVMDebugInfoPDB
    LLVMOption
    LLVMX86Disassembler
    LLVMX86AsmParser
    LLVMX86CodeGen
    LLVMGlobalISel
    LLVMSelectionDAG
    LLVMAsmPrinter
    LLVMDebugInfoCodeView
    LLVMX86Desc
    LLVMDemangle
    LLVMX86Info
    LLVMX86AsmPrinter
    LLVMX86Utils
    LLVMIRReader
    LLVMBitReader
    LLVMAsmParser
    LLVMMCDisassembler
    LLVMMCParser
    LLVMInstrumentation
    LLVMMCJIT
    LLVMOrcJIT
    LLVMCodeGen
    LLVMScalarOpts
    LLVMInstCombine
    LLVMAggressiveInstCombine
    LLVMTransformUtils
    LLVMAnalysis
    LLVMProfileData
    LLVMRuntimeDyld
    LLVMExecutionEngine
    LLVMTarget
    LLVMMC
    LLVMObject
    LLVMCore
    LLVMBinaryFormat
    LLVMSupport
    )
    
target_include_directories(${__TARGET_ADD_DEPENDENCY_TARGET} 
    PRIVATE
        ${mdl-jit-llvm_SOURCE_DIR}/dist/include
        ${mdl-jit-llvm_BINARY_DIR}/dist/include
    )

if(NOT __TARGET_ADD_DEPENDENCY_NO_LINKING)

    # avoid the transitive dependencies here to be able to create a linker group
    # since we simply link all llvm libs, the transitive dependencies are covered
    foreach(_LIB ${_LLVM_LIB_NAMES})
        list(APPEND _STATIC_LIB_FILE_LIST $<TARGET_FILE:${_LIB}>)
        # add_dependencies(${__TARGET_ADD_DEPENDENCY_TARGET} ${_LIB}) # add dependency manually
    endforeach()

    target_link_libraries(${__TARGET_ADD_DEPENDENCY_TARGET} 
        PRIVATE
            ${LINKER_START_GROUP}
            ${_STATIC_LIB_FILE_LIST}
            ${LINKER_END_GROUP}
        )

    add_dependencies(${__TARGET_ADD_DEPENDENCY_TARGET} mdl-jit-llvm) # add dependency manually
endif()
