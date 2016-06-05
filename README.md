# qt_open_icon #

## 项目特色 ##
借鉴WEB前端开发中图标使用字体库的方式生成，把这种方法也运用到QT开发中，摒弃传统的贴图方式，让你在QT开发中从繁琐的图片维护中解放出来。以此为核心，再增加各种常用组件。**我们旨在开发一个全面而又方便使用的QT组件库，所以希望志同道合的码友们能贡献自己的图库和组件源码。**

## 运行说明 ##
基于qt5.2.1编译，需要把项目resourse下的ttf字体库文件放到运行目录下或重新指定字体库路径；如果是其它版本qt库，可能需要更改头文件。

## 说明文档 ##
**1. 使用字体库生成图标**
提供了*IconHelper*类，使用这个类可以方便的在widget上加入图标,比如我们想要在一个button上增加一个微信图标，那么可以这么写：

    IconHelper::Instance()->setNewIcon(MuiFont());  //选择含有微信图标的字体库
    QPushButton *btn = new QPushButton;
    iconhelp::setIcon(btn,MuiFont::ICON_WEINXIN);

字体库需要从网上去找或者团队UI制作，这部分文档可以参照后面提供的*阿里巴巴矢量图库*文档使用。













## 以下是我们使用的开源矢量图库地址： ##
1. 阿里巴巴矢量图库 [http://iconfont.cn/](http://iconfont.cn/ "阿里巴巴矢量图库 ")
2. Awesome [http://fontawesome.io/cheatsheet/](http://fontawesome.io/cheatsheet/ "Awesome")
3. mui图库 [http://dev.dcloud.net.cn/mui/ui/#icon](http://dev.dcloud.net.cn/mui/ui/#icon "mui图库") (*这个团队应该也是使用阿里巴巴矢量图，字体文件名称都是iconfont，这样会造成两个库同时使用时其中后加载失效，所以最好以阿里矢量库为主，更全一些*)