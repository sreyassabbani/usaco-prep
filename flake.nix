{
  inputs = {
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0";
  };

  outputs = { self, nixpkgs, ... }:
  let
    system = "aarch64-darwin";
    pkgs = import nixpkgs { inherit system; };
    llvm = pkgs.llvmPackages_21;
  in
  {
    devShells.${system}.default =
      (pkgs.mkShell.override { stdenv = llvm.stdenv; }) {
        packages = [
          llvm.clang
          llvm.clang-tools  # clangd, clang-format
          llvm.lldb         # gives you lldb-dap too
          pkgs.cmake
        ];

        shellHook = ''
          if [ -t 1 ]; then
            printf '%b\n' "\033[1;32m[FLAKE]\033[0m Nix dev shell activated"
          fi
        '';
      };
  };
}
