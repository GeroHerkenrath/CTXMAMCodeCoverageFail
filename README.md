# Demo illustrating how code coverage breaks when using the Citrix MDM SDK > 23.11.0.4 (iOS) #

When integrating the Citrix MDM SDK for a version greater than 23.11.0.4 in a regular iOS project
code coverage seems to no longer work.

The exact error comes from `llvm-profdata` so I assume it has to do with perhaps an outdated toolchain
that was used when building the static libraries (or at least one of them).

The exact error is:
```
Showing All Issues
Failed to merge raw profiles in directory <...>/DerivedData/CTXMAMCodeCoverageFail-fftwxsloafuttualgnnmobfmnvaq/Build/ProfileData/00008027-000A40D42262802E to destination <...>/DerivedData/CTXMAMCodeCoverageFail-fftwxsloafuttualgnnmobfmnvaq/Build/ProfileData/00008027-000A40D42262802E/Coverage.profdata: Aggregation tool '<...>/llvm-profdata' failed with exit code 1: warning: <...>/DerivedData/CTXMAMCodeCoverageFail-fftwxsloafuttualgnnmobfmnvaq/Build/ProfileData/00008027-000A40D42262802E/7B5FB9D3-A66E-456C-854F-155C20768CE2-3819.profraw: invalid instrumentation profile data (file header is corrupt)
error: no profile can be merged
```

I tested this on an Intel based MacBook Pro as I have no chance to try an Apple Silicon at the moment.
However, the problem occurs both, on device and in the simulator (the latter being much more problematic 
as that is used in a build pipeline for CICD).
