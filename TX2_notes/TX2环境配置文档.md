TX2环境配置说明文档：

作者：李 顺

方法一（推荐）：已有系统替换
1. 本文件夹中的backup.tgz是已经配置好的TX2的环境的完整备份文件，基于 Nvidia Jetpack3.3.1，包含：
    * ubuntu16.04
    * ros-kinetic-desktop-full
    * Python3.5+tensorflow-1.14-gpu+opencv3.4.1
    * Pythion2.7+opencv3.4.1
    * CUDA9.0
    * TensorRT 4.0
    * intel-realsense lib
    * intel-realsense SDK （在~/catkin_ws/src/）下
    * Moveit

2. 安装方法（重要！！）：

    Step 1 准备HOST主机：

            * 准备一台装有ubuntu16.04的电脑或者虚拟机，空环境即可。注意一定是16.04版本。

            * 选择本文件夹中的sdkmanager.deb安装包，使用 sudo dpkg -i 命令或者直接双击安装；

            * 打开安装好的sdkmanager，如果需要更新直接更新。

            * 用usb数据线链接HOST主机以及TX2；

    Step 2 烧写系统：

            * 在sdkmanager中为Target(也就是TX2）选择需要安装的包，此处只是借助sdkmanager安装系统，所以只选择OS（操作系统）
                其余的Computer Version 部分不要勾选

            * 在sdkmanager中不要给HOST主机安装CUDA等包

            * 点击下一步

            * sdkmanager首先会下载需要的包，之后进行flash image os 制作，整个进度条大概在50%时，会进行TX2的确认
                此处注意保留默认配置，不要更改，之后选择manual模式；

            * 之后长按TX2电源，长按Recovery 再确认之后进入强制恢复模式，此时HOST主机上的sdkmanager开始烧写。

    Step 3 还原系统：

            * 拔掉TX2与HOST主机的链接，开机之后进入桌面：

            * 打开终端输入：
                sudo su 切换root用户

            * 利用cd命令导航到backup.tgz文件所在的文件夹（root 用户）

            * 执行 tar xvpfz backup.tgz -C / 覆盖掉新系统，替换为已经配置好的系统

            * reboot

方法二：重新配置
1. 为TX2烧写基本环境：

    Step 1 准备HOST主机：

            * 准备一台装有ubuntu16.04的电脑或者虚拟机，空环境即可。注意一定是16.04版本。

            * 选择本文件夹中的sdkmanager.deb安装包，使用 sudo dpkg -i 命令或者直接双击安装；

            * 打开安装好的sdkmanager，如果需要更新直接更新。

            * 用usb数据线链接HOST主机以及TX2；

    Step 2 烧写系统：

            * 在sdkmanager中为Target(也就是TX2）选择需要安装的包，务必选择：Computer Version (包含CUDA以及opencv)
                下的各个包，可选AI等包

            * 在sdkmanager中不要给HOST主机安装CUDA等包

            * 点击下一步

            * sdkmanager首先会下载需要的包，之后进行flash image os 制作，整个进度条大概在50%时，会进行TX2的确认
                此处注意保留默认配置，不要更改，之后选择auto模式；

            * 之后长按TX2电源，长按Recovery 再确认之后进入强制恢复模式，此时HOST主机上的sdkmanager开始烧写。

            * 烧写完成之后，系统TX2基本系统已经装完，但是所选择的包需要通过同一局域网条件下进行安装，具体可参考：
            https://zhuanlan.zhihu.com/p/165989685

            * 之后，TX2自动开机，讲TX2以及HOST主机在同一局域网之下之后，sdkmanager便会自动给TX2安装之前选好的包

            * 完成后 reboot

2. 检查基本环境：

            * 备份并替换国内apt源

                    sudo cp /etc/apt/sources.list /etc/apt/sources.list.backup
                    sudo gedit /etc/apt/source.list

                    用以下内容替换原有内容 保存 退出

                    deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-updates main restricted universe multiverse  
                    deb-src http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-updates main restricted universe multiverse   
                    deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-security main restricted universe multiverse   
                    deb-src http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-security main restricted universe multiverse   
                    deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-backports main restricted universe multiverse   
                    deb-src http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial-backports main restricted universe multiverse   
                    deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial main universe restricted   
                    deb-src http://mirrors.tuna.tsinghua.edu.cn/ubuntu-ports/ xenial main universe restricted  kk

            * 更新apt-get

                    sudo apt-get update
                    sudo apt-get upgrade

            * 安装pip以及pip3

                    sudo apt install python-pip
                    sudo apt install python3-pip

            * 终端输入nvcc --version 获得CUDA版本即可。否则直接返回第一步，重新烧写。

            * 终端输入python
                        之后import cv2，无报错，说明python2已经找到了opencv
            * 终端输入python3
                        之后import cv2，无报错，说明python3已经找到了opencv
            * 若Python3没有找到cv2，则安装出错，选择重新烧写或者手动编译安装opencv3.4.1

*3. 手动编译安装opencv3.4.1

            * opencv官网下载Source code 3.4.1

            * 打开终端，依次输入， 完成编译opencv之前的准备
                    sudo apt-get purge libopencv*
                    sudo apt-get purge python-numpy
                    sudo apt autoremove
                    sudo apt-get update
                    sudo apt-get dist-upgrade
                    sudo apt-get install --only-upgrade g++-5 cpp-5 gcc-5
                    sudo apt-get install build-essential make cmake cmake-curses-gui \
                         g++ libavformat-dev libavutil-dev \
                         libswscale-dev libv4l-dev libeigen3-dev \
                         libglew-dev libgtk2.0-dev
                    sudo apt-get install libdc1394-22-dev libxine2-dev \
                             libgstreamer1.0-dev \
                             libgstreamer-plugins-base1.0-dev
                    sudo apt-get install libjpeg8-dev libjpeg-turbo8-dev libtiff5-dev \
                                 libjasper-dev libpng12-dev libavcodec-dev
                    sudo apt-get install libxvidcore-dev libx264-dev libgtk-3-dev \
                                     libatlas-base-dev gfortran
                    sudo apt-get install libopenblas-dev liblapack-dev liblapacke-dev
                    sudo apt-get install qt5-default

            * 继续输入:
                    sudo apt-get install
                    libglew-dev  \
                        libtiff5-dev \
                        zlib1g-dev \
                        libjpeg-dev \
                        libpng12-dev \
                        libjasper-dev \
                        libavcodec-dev \
                        libavformat-dev \
                        libavutil-dev \
                        libpostproc-dev \
                        libswscale-dev \
                        libeigen3-dev \
                        libtbb-dev \
                        libgtk2.0-dev \
                        pkg-config

            * 执行Python3绑定：

            sudo apt-get install python3-dev python3-numpy python3-py python3-pytest

            * OpenCV-3.4.1文件夹下去创建 build,  并在build 文件夹下创建 CMakeLists.txt文件,
              然后在 CMakeLists.txt 里面写入下面的命令:
                  cmake \
                        -DCMAKE_BUILD_TYPE=Release \
                        -DCMAKE_INSTALL_PREFIX=/home/nvidia/OpenCV3.4_with_contrib/install \
                        -DBUILD_PNG=OFF \
                        -DBUILD_TIFF=OFF \
                        -DBUILD_TBB=OFF \
                        -DBUILD_JPEG=OFF \
                        -DBUILD_JASPER=OFF \
                        -DBUILD_ZLIB=OFF \
                        -DBUILD_EXAMPLES=OFF \
                        -DBUILD_opencv_java=OFF \
                        -DBUILD_opencv_python2=OFF \
                        -DBUILD_opencv_python3=ON \
                        -DENABLE_PRECOMPILED_HEADERS=OFF \
                        -DWITH_OPENCL=OFF \
                        -DWITH_OPENMP=OFF \
                        -DWITH_FFMPEG=ON \
                        -DWITH_GSTREAMER=OFF \
                        -DWITH_GSTREAMER_0_10=OFF \
                        -DWITH_CUDA=ON \
                        -DWITH_GTK=ON \
                        -DWITH_VTK=OFF \
                        -DWITH_TBB=ON \
                        -DWITH_1394=OFF \
                        -DWITH_OPENEXR=OFF \
                        -DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda-9.0 \
                        -DCUDA_ARCH_BIN=6.2 \
                        -DOPENCV_EXTRA_MODULES_PATH = /home/nvidia/OpenCV3.4_with_contrib/opencv_contrib-3.4.3/modules \
                        -DCUDA_ARCH_PTX="" \
                        -DINSTALL_C_EXAMPLES=ON \
                        -DINSTALL_TESTS=OFF \
                        -DOPENCV_TEST_DATA_PATH="" \
                        ../opencv

            * 在build中执行 cmake ..

            * 之后进行make -j6

            * sudo make install

            * 查看 include 头文件和 lib文件, 并添加到系统路径

            * 打开Python3以及Python2，检验导入情况

4. 手动安装Tensorflow1.14-gpu

            * 从Nvidia官网的Jetpack网站下载相应版本的tensorflow-gpu-cp35.wheel

            * 使用sudo pip3 install tensorflow-gpu....

            * 中间出现各种包的依赖问题时，如果出现类似于“can not find the wheel for this platform"
                时，说明这个python的包没有预先编译好的为arm平涛使用的wheel文件，需要去github下载相应版本
                的源码文件进行编译安装

5. 安装ros-kinetic-desktop-full

    Step 1 添加source list

            * sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

    Step 2 设置key

            * sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

    Step 3 更新

            * sudo apt-get update

    Step 4 安装ros

            * sudo apt-get install ros-kinetic-desktop-full

    Step 5 环境变量设置

            * echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc

            * source ~/.bashrc

    Step 6 安装编译依赖

            * sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential

    Step 7 初始化rosdep

            * sudo apt install python-rosdep
            * sudo rosdep init
            * rosdep update

6. 安装intel-realsense-SDK

    Step 1 安装intel-realsense-lib库文件

            * 注册key
                sudo apt-key adv --keyserver keys.gnupg.net --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE || sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-key F6E65AC044F831AC80A06380C8B3A55A6F3EFCDE

            * 添加软件源：
                sudo add-apt-repository "deb http://realsense-hw-public.s3.amazonaws.com/Debian/apt-repo xenial main" -u

            * 安装库文件
                sudo apt-get install librealsense2-dkms
                sudo apt-get install librealsense2-utils

            * 安装可选项
                sudo apt-get install librealsense2-dev
                sudo apt-get install librealsense2-dbg

    Step 2 编译intel-realsense-SDK ros功能包

            * 打开终端，执行:
                mkdir -p ~/catkin_ws/src
                cd ~/catkin_ws/src/

            * 初始化工作空间：
                catkin_workspace_init
                cd ~/catkin_ws
                catkin_make

            * 下载SDK的源码：
                git clone https://github.com/IntelRealSense/realsense-ros.git

            * 切换分支
                cd realsense-ros/
                git checkout `git tag | sort -V | grep -P "^\d+\.\d+\.\d+" | tail -1`
                cd ..

            *工作空间编译：
                cd ~/catkin_ws
                catkin_make

            * 环境配置
		echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
		source ~/.bashrc

            *编译时遇到ros功能包依赖问题，则按照make的报错信息进提示行包的安装
    Step 3 验证功能包

            * 安装rviz
                sudo apt-get install ros-kinetic-rviz

            * 启动demo
                roslaunch realsense2_camera rs_camera.launch
                rviz
                在rviz中 左上角Displays中Fixed Frame选择camera_link 此时Global Status变绿
                在左下角add菜单by topic中选择要显示的相机topic
