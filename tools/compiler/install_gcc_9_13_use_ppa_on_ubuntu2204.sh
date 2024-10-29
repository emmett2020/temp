set -ex
sudo apt install software-properties-common -y
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y
sudo apt update

# Support version 9~13
apt install gcc-13
