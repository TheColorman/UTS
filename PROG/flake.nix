{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    nixpkgs-patched = (import nixpkgs {inherit system;}).applyPatches {
      name = "nixpkgs-update-oraclejdk";
      src = nixpkgs;
      patches = [./nixpkgs-update-oraclejdk.patch];
    };
    pkgs = import nixpkgs-patched {
      inherit system;
      config = {allowUnfree = true;};
    };
  in {
    packages.x86_64-linux.default = pkgs.writeShellApplication {
      name = "focp-coding";
      runtimeInputs = with pkgs; [oraclejdk8];
      text = ''
        code ~/ITU/Repos/UTS
      '';
    };

    devShells.x86_64-linux.default = pkgs.mkShell {
      packages = with pkgs; [oraclejdk8];
    };
  };
}
