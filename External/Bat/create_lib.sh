cd /data/coding/External

#! 编译boost库
version="1.88.0" 
boost_dir="boost_1_88_0" 

if [ ! -f /data/coding/External/boost_installed.txt ]; then

	if [ ! -f ${boost_dir}.tar.gz ]; then
		wget https://archives.boost.io/release/${version}/source/${boost_dir}.tar.gz
	fi 
	
	if [ ! -f /data/coding/External/boost_download.txt ]; then
		tar -zxvf ${boost_dir}.tar.gz
		rm -rf boost
		mv ${boost_dir} boost
		touch /data/coding/External/boost_download.txt
	fi 
	
	cd boost
	
	if [ ! -f b2 ]; then
		./bootstrap.sh --with-libraries=all --with-toolset=gcc
	fi 
	
	./b2 install --prefix=/data/coding/Libs/boost/stage/ cxxflags="-std=c++20"
	touch /data/coding/Libs/boost_installed.txt
	
fi
