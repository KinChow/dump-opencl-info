# DumpOpenCLInfo

#### 介绍
用于获取OpenCL platform/device信息工具



#### 安装教程

```shell
python build.py --platform=Windows
python build.py --clean
```

运行build.py安装程序，选项如下：

* platform：可以选择运行平台（Windows、Android、Linux），默认为Windows
* clean：清空构建目录和安装目录



#### 使用说明

```shell
./DumpOpenCLInfo --format=console
```

运行DumpOpenCLInfo，选项如下：

* format：
  * console：终端形式打印
  * json：json形式打印
