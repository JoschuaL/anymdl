#===-- LLVMBuild.cmake - LLVMBuild Configuration for LLVM -----*- CMake -*--===#
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
#===------------------------------------------------------------------------===#
#
# This file contains the LLVMBuild project information in a format easily
# consumed by the CMake based build system.
#
# This file is autogenerated by llvm-build, do not edit!
#
#===------------------------------------------------------------------------===#


# LLVMBuild CMake fragment dependencies.
#
# CMake has no builtin way to declare that the configuration depends on
# a particular file. However, a side effect of configure_file is to add
# said input file to CMake's internal dependency list. So, we use that
# and a dummy output file to communicate the dependency information to
# CMake.
#
# FIXME: File a CMake RFE to get a properly supported version of this
# feature.
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/bindings/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/docs/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/examples/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Analysis/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/AsmParser/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Bitcode/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Bitcode/Reader/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Bitcode/Writer/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/CodeGen/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/CodeGen/AsmPrinter/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/CodeGen/SelectionDAG/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/CodeGen/MIRParser/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/CodeGen/GlobalISel/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/DWARF/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/MSF/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/CodeView/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/PDB/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/DebugInfo/Symbolize/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Demangle/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/MCJIT/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/RuntimeDyld/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/IntelJITEvents/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/OProfileJIT/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Orc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/PerfJITEvents/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/FuzzMutate/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/LineEditor/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Linker/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/IR/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/IRReader/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/LTO/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/MC/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/MC/MCDisassembler/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/MC/MCParser/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Object/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/BinaryFormat/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ObjectYAML/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Option/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Passes/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ProfileData/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ProfileData/Coverage/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Support/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/TableGen/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/NVPTX/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/NVPTX/InstPrinter/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/NVPTX/MCTargetDesc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/NVPTX/TargetInfo/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/AsmParser/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/Disassembler/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/InstPrinter/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/MCTargetDesc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/TargetInfo/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Target/X86/Utils/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Testing/Support/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ToolDrivers/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ToolDrivers/llvm-dlltool/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ToolDrivers/llvm-lib/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/AggressiveInstCombine/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/Coroutines/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/IPO/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/InstCombine/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/Instrumentation/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/Scalar/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/Utils/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/Vectorize/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Transforms/ObjCARC/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/WindowsManifest/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/projects/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/bugpoint/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/dsymutil/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/lli/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/lli/ChildTarget/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-ar/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-as/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-bcanalyzer/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-cat/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-cfi-verify/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-cov/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-cvtres/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-diff/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-dis/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-dwarfdump/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-dwp/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-exegesis/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-extract/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-jitlistener/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-link/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-lto/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-mc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-mca/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-modextract/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-mt/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-nm/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-objcopy/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-objdump/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-pdbutil/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-profdata/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-rc/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-rtdyld/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-size/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-split/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/llvm-undname/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/opt/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/tools/verify-uselistorder/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/TableGen/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/unittest/LLVMBuild.txt"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/llvm-build/llvm-build"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/llvm-build/llvmbuild/__init__.py"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/llvm-build/llvmbuild/main.py"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/llvm-build/llvmbuild/componentinfo.py"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)
configure_file("/Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/llvm-build/llvmbuild/util.py"
               ${CMAKE_CURRENT_BINARY_DIR}/DummyConfigureOutput)

# Explicit library dependency information.
#
# The following property assignments effectively create a map from component
# names to required libraries, in a way that is easily accessed from CMake.
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDemangle )
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMSupport LLVMDemangle)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMBinaryFormat LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMCore LLVMBinaryFormat LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMBitReader LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDebugInfoMSF LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDebugInfoCodeView LLVMDebugInfoMSF LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMMC LLVMBinaryFormat LLVMDebugInfoCodeView LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMMCParser LLVMMC LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMObject LLVMBinaryFormat LLVMBitReader LLVMCore LLVMMC LLVMMCParser LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMProfileData LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMAnalysis LLVMBinaryFormat LLVMCore LLVMObject LLVMProfileData LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMTransformUtils LLVMAnalysis LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMAggressiveInstCombine LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMAsmParser LLVMBinaryFormat LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMBitWriter LLVMAnalysis LLVMCore LLVMMC LLVMObject LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMInstCombine LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMScalarOpts LLVMAggressiveInstCombine LLVMAnalysis LLVMCore LLVMInstCombine LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMTarget LLVMAnalysis LLVMCore LLVMMC LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMCodeGen LLVMAnalysis LLVMBitReader LLVMBitWriter LLVMCore LLVMMC LLVMProfileData LLVMScalarOpts LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMAsmPrinter LLVMAnalysis LLVMBinaryFormat LLVMCodeGen LLVMCore LLVMDebugInfoCodeView LLVMDebugInfoMSF LLVMMC LLVMMCParser LLVMSupport LLVMTarget)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMIRReader LLVMAsmParser LLVMBitReader LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMLinker LLVMCore LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMVectorize LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMInstrumentation LLVMAnalysis LLVMCore LLVMMC LLVMProfileData LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMipo LLVMAggressiveInstCombine LLVMAnalysis LLVMBitReader LLVMBitWriter LLVMCore LLVMIRReader LLVMInstCombine LLVMInstrumentation LLVMLinker LLVMObject LLVMProfileData LLVMScalarOpts LLVMSupport LLVMTransformUtils LLVMVectorize)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMCoroutines LLVMAnalysis LLVMCore LLVMScalarOpts LLVMSupport LLVMTransformUtils LLVMipo)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMCoverage LLVMCore LLVMObject LLVMProfileData LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDebugInfoDWARF LLVMBinaryFormat LLVMMC LLVMObject LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDebugInfoPDB LLVMDebugInfoCodeView LLVMDebugInfoMSF LLVMObject LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMOption LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMDlltoolDriver LLVMObject LLVMOption LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMRuntimeDyld LLVMMC LLVMObject LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMExecutionEngine LLVMCore LLVMMC LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTarget)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMMCJIT LLVMCore LLVMExecutionEngine LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTarget)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMFuzzMutate LLVMAnalysis LLVMBitReader LLVMBitWriter LLVMCore LLVMScalarOpts LLVMSupport LLVMTarget)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMGlobalISel LLVMAnalysis LLVMCodeGen LLVMCore LLVMMC LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMInterpreter LLVMCodeGen LLVMCore LLVMExecutionEngine LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMObjCARCOpts LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMPasses LLVMAggressiveInstCombine LLVMAnalysis LLVMCodeGen LLVMCore LLVMInstCombine LLVMInstrumentation LLVMScalarOpts LLVMSupport LLVMTarget LLVMTransformUtils LLVMVectorize LLVMipo)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMLTO LLVMAggressiveInstCombine LLVMAnalysis LLVMBitReader LLVMBitWriter LLVMCodeGen LLVMCore LLVMInstCombine LLVMLinker LLVMMC LLVMObjCARCOpts LLVMObject LLVMPasses LLVMScalarOpts LLVMSupport LLVMTarget LLVMTransformUtils LLVMipo)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMLibDriver LLVMBinaryFormat LLVMObject LLVMOption LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMLineEditor LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMMCDisassembler LLVMMC LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMMIRParser LLVMAsmParser LLVMBinaryFormat LLVMCodeGen LLVMCore LLVMMC LLVMSupport LLVMTarget)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMNVPTXAsmPrinter LLVMMC LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMNVPTXInfo LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMNVPTXDesc LLVMMC LLVMNVPTXAsmPrinter LLVMNVPTXInfo LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMSelectionDAG LLVMAnalysis LLVMCodeGen LLVMCore LLVMMC LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMNVPTXCodeGen LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMNVPTXAsmPrinter LLVMNVPTXDesc LLVMNVPTXInfo LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils LLVMVectorize LLVMipo)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86Utils LLVMCore LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86AsmPrinter LLVMMC LLVMSupport LLVMX86Utils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86Info LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86Desc LLVMMC LLVMMCDisassembler LLVMObject LLVMSupport LLVMX86AsmPrinter LLVMX86Info)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86CodeGen LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMGlobalISel LLVMMC LLVMSelectionDAG LLVMSupport LLVMTarget LLVMX86AsmPrinter LLVMX86Desc LLVMX86Info LLVMX86Utils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMObjectYAML LLVMDebugInfoCodeView LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMOrcJIT LLVMCore LLVMExecutionEngine LLVMMC LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMSymbolize LLVMDebugInfoDWARF LLVMDebugInfoPDB LLVMDemangle LLVMObject LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMTableGen LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMTestingSupport LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMWindowsManifest LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86AsmParser LLVMMC LLVMMCParser LLVMSupport LLVMX86AsmPrinter LLVMX86Desc LLVMX86Info)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_LLVMX86Disassembler LLVMMCDisassembler LLVMSupport LLVMX86Info)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_gtest LLVMSupport)
set_property(GLOBAL PROPERTY LLVMBUILD_LIB_DEPS_gtest_main gtest)