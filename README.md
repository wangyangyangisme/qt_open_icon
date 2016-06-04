# qt_open_icon #

有木有在做QT项目时候为了一个按钮不同状态贴图而烦恼，命名只需要变化图标几种颜色，却必须贴若干个图，即难维护又浪费存储资源。这个小项目就能帮到你。我们脱离笨重的贴图，仅仅使用非常小的字体库。这样做有如下优点：

 - 多个图标字体合成一个字体文件，避免每张图片都需要联网请求；
 - 字体可任意缩放，而图片放大会失真、缩小则浪费像素；
 - 可通过css任意改变颜色、大小等

**运行说明**

基于qt5.2.1编译，需要把项目resourse下的ttf字体库文件放到运行目录下

**我们的最终目标是做一个漂亮的开源QT组件库，所以希望志同道合的战友们能贡献图库和组件源码**

## 以下是我们使用的开源矢量图库地址： ##
1. 阿里巴巴矢量图库 [http://iconfont.cn/](http://iconfont.cn/ "阿里巴巴矢量图库 ")
2. Awesome [http://fontawesome.io/cheatsheet/](http://fontawesome.io/cheatsheet/ "Awesome")
3. mui图库 [http://dev.dcloud.net.cn/mui/ui/#icon](http://dev.dcloud.net.cn/mui/ui/#icon "mui图库") (*这个团队应该也是使用阿里巴巴矢量图，字体文件名称都是iconfont，这样会造成两个库同时使用时其中后加载失效，所以最好以阿里矢量库为主，更全一些*)
