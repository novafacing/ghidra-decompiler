## Quickstart

```
nix-shell
make
make -j9 sleigh_opt
./sleigh_opt -a ./specs
make -j9 libdecomp_dbg
./libdecomp_dbg <binary> <out_file_name.c> # (ex ./libdecomp_dbg tests/lab5-src/test_array out.c)
```

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

To make the ghidra_dbg decompiler which we talk to with bindara, do:
```sh
nix-shell
make -j9 ghidra_dbg
```

### Documentation

```
make doc
```

Protip: the docs are BAD

## Usage

To compile all slaspec to sla:

```
make -j8 sleigh_opt
./sleigh_opt -a ./specs # (AKA Ghidra/Processors/)
```

This can take a while depending on your machine so make a cuppa joe. This will compile all slaspec files to .sla files. Luckily for us we also have all our .ldefs &etc files there too. I've provided this sans-ghidra-core so that should work prettily, but all the .sla files are like 17M each so I've excluded them.

Compiling the interactive command line decompiler:

```
make -j9 decomp_dbg
```

Running the interactive command line decompiler:

```
./decomp_dbg -s ./specfiles # Requires building sleigh spec files above under usage

```

Commands usable are:
```
#
%
//
addpath
adjust vma
analyze range
binary
break action
break jumptable
break start
callgraph build
callgraph build quick
callgraph dump
callgraph list
callgraph load
clear architecture
closefile
codedata dump crossrefs
codedata dump hits
codedata dump starts
codedata dump targethits
codedata dump unlinked
codedata init
codedata run
codedata target
comment instruction
continue
count pcode
deadcode delay
debug action
decompile
disassemble
dump
duplicate hash
echo
fixup call
fixup callother
force dec
force goto
force hex
global add
global registers
global remove
global spaces
graph controlflow
graph dataflow
graph dom
history
list action
list override
list prototypes
load addr
load file
load function
map address
map externalref
map function
map hash
map label
name varnode
openfile
openfile append
openfile write
option
override flow
override jumptable
override prototype
paramid analysis
parse file
parse line
prefersplit
print C
print C flat
print C globals
print C types
print C xml
print actionstats
print cover high
print cover varnode
print cover varnodehigh
print extrapop
print high
print inputs
print inputs all
print language
print localrange
print map
print parammeasures
print parammeasures xml
print raw
print spaces
print tree block
print tree varnode
print varnode
produce C
produce prototypes
prototype lock
prototype unlock
quit
read symbols
remove
rename
reset actionstats
restore
retype
save
set context
set track
source
structure blocks
trace address
trace break
trace clear
trace disable
trace enable
trace list
type varnode
volatile
```

To load a file:
```
load file <filename>
```

Now, from here basically everything operates on functions, so we need to analyze first.

Print program mapping (functions and addresses)

```
read symbols
print map
```

To test decompile:

```
load file <filename>
read symbols
produce C out.c
```

