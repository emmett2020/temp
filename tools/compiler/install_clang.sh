# https://apt.llvm.org/
# Support all ubuntu platforms

wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh $1
rm llvm.sh
