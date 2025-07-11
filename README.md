# WOOO!! 🎉

Thought I would discipline myself. Feel free to judge me for premature optimization, naming conventions, commit messages—no really, open an issue or PR and I'll try to better myself.

---

## Structure


### Overview
```
.
├── .clang-format
├── .gitignore
├── .playground/
│   └── ...
├── [level]/
│   └── ...
├── compile_flags.txt
└── README.md
```

### Levels
```
[level]
├── [category]
│   ├── [problem]
│   │   └── main.cpp
│   └── x
└── x
```

`[level]`: Canonical USACO levels
`[category]`: As outlined by the [USACO Guide](https://usaco.guide)
`[problem]`: USACO problems (mostly those suggested by the guide)

### Playground
```
.playground
├── [topic]
│   ├── comp.cpp
│   ├── idiomatic.cpp
│   └── [other].cpp
└── x
```

The playground is broken down into topics (e.g. `trees`, `graphs`), each of which has a `comp.cpp` (without best practices, to get used to writing contest-type solutions), sometimes an `idiomatic.cpp` (best practices, smart pointers, RAII, etc), and even sometimes another file with interesting deviations or implementations with a design pattern.
