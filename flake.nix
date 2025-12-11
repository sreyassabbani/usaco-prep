{
  inputs = {
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0";
  };

  outputs = { self, nixpkgs, ... }:
  let
    system = "aarch64-darwin";
    pkgs = nixpkgs.legacyPackages.${system};
  in
  {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = with pkgs; [
        clang
        cmake
      ];

      shellHook = ''
        if [ -t 1 ]; then
          printf '%b\n' "\033[1;32m[FLAKE]\033[0m \033[0mNix dev shell activated\033[0m"
        fi
      '';
    };
  };
}
