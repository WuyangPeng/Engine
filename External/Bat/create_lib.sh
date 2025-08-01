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
	
	./b2 install --prefix=/data/coding/External/boost/stage/ cxxflags="-std=c++20"
	touch /data/coding/External/boost_installed.txt
	
fi

ace_config="/data/coding/External/ACE/ACE_wrappers/ace/config.h"
ace_platform_macros_gnu="/data/coding/External/ACE/ACE_wrappers/include/makeinclude/platform_macros.GNU"

if [ ! -f /data/coding/External/ace_installed.txt ]; then

    cd /data/coding/External/
	
	if [ ! -f /data/coding/External/ace_installed_clone.txt ]; then
	
		rm -rf ACE
	 
		if [ ! -f /data/coding/External/ACE-8.0.4.tar.gz ]; then
			wget -O /data/coding/External/ACE-8.0.4.tar.gz https://github.com/DOCGroup/ACE_TAO/releases/download/ACE%2BTAO-8_0_4/ACE-8.0.4.tar.gz
		fi
		
		# 检查下载是否成功
		if [ $? -eq 0 ]; then
		
			mkdir /data/coding/External/ACE
			
			# 解压下载的文件
			tar -xzf /data/coding/External/ACE-8.0.4.tar.gz -C /data/coding/External/ACE

			# 检查解压是否成功
			if [ $? -eq 0 ]; then
				# 创建标志文件
				touch /data/coding/External/ace_installed_clone.txt 
			else
				echo "解压失败"
			fi
		else
			echo "下载失败"
		fi
	
	fi 
	
	if [ -f /data/coding/External/ace_installed_clone.txt ]; then
	
		# 创建新的 config.h 文件
		echo "#ifndef _CONFIG_H_" > "$ace_config"
		echo "#define _CONFIG_H_" >> "$ace_config"
		echo "#include \"ace/config-linux.h\"" >> "$ace_config"
		echo "#endif" >> "$ace_config"

		# 创建新的 platform_macros.GNU 文件
		echo "include /data/coding/External/ACE/ACE_wrappers/include/makeinclude/platform_linux.GNU" > "$ace_platform_macros_gnu"	
	
		export ACE_ROOT="/data/coding/External/ACE/ACE_wrappers"
	
		cd /data/coding/External/ACE/ACE_wrappers		
		 
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/External/ace_installed.txt
	
		fi
	
	fi
	
fi  

mysql_connector_cpp_tag="9.4.0"

if [ ! -f /data/coding/External/mysql_connector_cpp_installed.txt ]; then

    cd /data/coding/External/
	
	if [ ! -f /data/coding/External/mysql_connector_cpp_installed_clone.txt ]; then
	
		rm -rf mysql-connector-c++

		git clone https://github.com/mysql/mysql-connector-cpp.git mysql-connector-c++
		
		if [ $? -eq 0 ]; then 
		
			cd mysql-connector-c++
			git checkout "tags/${mysql_connector_cpp_tag}" -b "build-${mysql_connector_cpp_tag}"
			cd ..
	 
			touch /data/coding/External/mysql_connector_cpp_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/External/mysql_connector_cpp_installed_clone.txt ]; then
	
		cd /data/coding/External/mysql-connector-c++
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		
		cd /data/coding/External/mysql-connector-c++/build/cdk/protocol/mysqlx/protobuf
		make
		
		cd /data/coding/External/mysql-connector-c++/build
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/External/mysql_connector_cpp_installed.txt
	
		fi
	
	fi
	
fi


if [ ! -f /data/coding/External/protobuf_installed.txt ]; then

    cd /data/coding/External/
	
	if [ ! -f /data/coding/External/protobuf_installed_clone.txt ]; then
	
		rm -rf protobuf

		git clone https://github.com/protocolbuffers/protobuf.git
		
		if [ $? -eq 0 ]; then 
		
			cd protobuf
            git checkout v31.1
			git submodule update --init --recursive
            cd ..
	 
			touch /data/coding/External/protobuf_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/External/protobuf_installed_clone.txt ]; then
	
		cd /data/coding/External/protobuf
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release
		make
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/coding/External/protobuf_installed.txt
	
		fi
	
	fi
	
fi

if [ ! -f /data/coding/External/miniz_installed.txt ]; then

    cd /data/coding/External/
	
	if [ ! -f /data/coding/External/miniz_installed_clone.txt ]; then
	
		rm -rf miniz

		git clone https://github.com/richgel999/miniz
		
		if [ $? -eq 0 ]; then 
		
			cd miniz
			git checkout 3.0.2
			cd ..
	 
			touch /data/coding/External/miniz_installed_clone.txt
	
		fi
	
	fi 
	
	if [ -f /data/coding/External/miniz_installed_clone.txt ]; then
	
		cd /data/coding/External/miniz
	
		mkdir -p build
		cd build

		cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=ON
		make 
	 
		if [ $? -eq 0 ]; then 
	 
			touch /data/External/miniz_installed.txt
	
		fi
	
	fi
	
fi