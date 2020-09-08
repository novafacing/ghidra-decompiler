## Dependencies

```
binutils
libbfd
libibterty
zlib
doxygen # (Optional, for docs)
```


## Building

### Nix

```sh
nix-shell
make
```

### Documentation

```
make doc
```

## Usage

To compile all slaspec to sla:

```
make -j8 sleigh_opt
./sleigh_opt -a ./specs # (AKA Ghidra/Processors/)
```

This can take a while depending on your machine so make a cuppa joe. This will compile all slaspec files to .sla files. Luckily for us we also have all our .ldefs &etc files there too. I've provided this sans-ghidra-core so that should work prettily, but all the .sla files are like 17M each so I've excluded them.
