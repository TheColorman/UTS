{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: let
    pkgs = nixpkgs.legacyPackages.x86_64-linux;
  in {
    packages.x86_64-linux.default = pkgs.writeShellApplication {
      runtimeInputs = with pkgs; [ gcc14 gdb ];
      name = "start-focp";
      text = ''
        code /home/color/ITU/Repos/UTS
      '';
    };

    devShells.x86_64-linux.default = pkgs.mkShell {
      packages = with pkgs; [ gcc14 gdb ];
      shellHook = "code /home/color/ITU/Repos/UTS";
    };
  };
}
