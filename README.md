# string-operations-cpp

C++ lab — **String data structure and operations**. Implements a custom string class built on top of sequence abstractions (Dynamic Array, Linked List), with sorting and searching capabilities.

University lab.

## Implemented

- `StringList` / `StringVector` — string containers
- Operations: insert, delete, find, sort, concatenate
- Generic sequence base (`ISequence<T>`, `ArraySequence`, `ListSequence`)

## Build

```bash
mkdir build && cd build
cmake ..
make
./lab
```

## License

MIT
