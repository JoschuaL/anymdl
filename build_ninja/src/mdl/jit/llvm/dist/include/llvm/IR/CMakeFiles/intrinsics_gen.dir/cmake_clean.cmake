file(REMOVE_RECURSE
  "Attributes.inc"
  "Attributes.inc.tmp"
  "CMakeFiles/intrinsics_gen"
  "IntrinsicEnums.inc"
  "IntrinsicEnums.inc.tmp"
  "IntrinsicImpl.inc"
  "IntrinsicImpl.inc.tmp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/intrinsics_gen.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
