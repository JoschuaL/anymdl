# AnyMDL

A Fork of the NVIDIA MDL Library with AnyDSL impala added as an transpilation target.

For Usage Documentation, Build instructions, etc. of the normal MDL SDK, please consult the readme  on
[the official NVIDA github repo](https://github.com/NVIDIA/MDL-SDK).

For Documentation regarding the AnyDSL support, read on.



## Building AnyMDL from Source

Simply follow the steps as described on the [upstream github repo](https://github.com/NVIDIA/MDL-SDK)

### Testing the Build

In addition to the normal MDL SDK examples, you may also test the AnyMDL transpiler by
executing

```
$DIR/$BUILD/src/prod/bin/mdlc/mdlc -t AnyDSL -O3 -p $DIR/examples/mdl/nvidia/sdk_examples/ presentation_bump presentation_diffuse presentation_glossy presentation_perlin_noise
```

replacing $DIR with the location into which you cloned this repo, and $BUILD with the name of the directory you used to build the SDK in.

Alternatively, use the pre-defined mdlc cmake-target and run it using appropriate parameters


## Changes to the MDL SDK

Almost everything is unchanged compared to the official SDK. The only changes were made to the mdlc sub-project in
```
$DIR/src/prod/bin/mdlc/*
```

## Usage

use the mdlc executable with 


```
-t AnyDSL
```

All other flags, as well as path and import resolution mechanics can be taken from the official documentation
