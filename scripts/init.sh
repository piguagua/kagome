#!/usr/bin/env bash
set -ex
current_dir=$(dirname $(readlink -f "$0"))
parent_dir=$(dirname "$current_dir")
cd $parent_dir

set -a; source $current_dir/.env; set +a #include .env vars 

apt update
apt install --no-install-recommends -y \
      build-essential git gcc ca-certificates python-is-python3 python3-pip \
      python3-venv curl libgmp-dev libncurses6 libncurses-dev libnsl-dev libseccomp-dev

python3 -m venv "$parent_dir/venv"

echo "Python environment created successfully in $parent_dir/venv"

$parent_dir/venv/bin/pip install --no-cache-dir cmake==${CMAKE_VERSION} gitpython requests
