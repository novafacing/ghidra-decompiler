with import <nixpkgs> {}; 
stdenv.mkDerivation {
  name = "ghidra-decompiler";
  buildInputs = [
    binutils
    libbfd
    libiberty
    zlib
    doxygen
    radare2
  ];
}
