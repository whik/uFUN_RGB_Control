# uFUN_RGB_Ctrl

#### 介绍
基于uFUN开发板，实现通过Qt上位机控制uFUN开发板RGB灯亮度，主要包括STM32下位机程序和Qt上位机程序。

- Gitee项目地址：https://gitee.com/whik/uFUN_RGB_Control
- Github项目地址：https://github.com/whik/uFUN_RGB_Control

本项目基于uFUN 2.0版本开发，上位机使用Qt开发，下位机使用Keil MDK开发。

- Keil MDK版本：MDK V5.26
- Qt板：Qt 5.8.0

### uFUN开发板

[**uFun**](http://www.myufun.com/)是由[@张进东](https://www.mianbaoban.cn/blog/uid-me-1595057.html) 张工组织发起的一个开源的学习板，设计初衷是为了帮助学生更好的理解电子知识和开发技巧，同时又能对学生毕业找工作有很明显的帮助。张工于2014年10月提出这个想法，并发到了博客上，不久就得到了全国各地几十位小伙伴的支持和响应，大家天南海北，筹钱献力，多位在职工程师，利用业余时间共同设计了这块学习板，经过几次的设计验证，还有一些厂商的支持，400套学习板诞生了。

![](https://wcc-blog.oss-cn-beijing.aliyuncs.com/img/uFUN2_0/%E6%AD%A3%E9%9D%A24.jpeg)

uFUN不是一本死板的“教科书”，虽然只有4*6cm大小，但却包含SD卡槽、三轴加速度计、触摸按键、蜂鸣器、RGB LED、串口芯片、低通滤波电路、双T陷波滤波器等，方便携带，开发简单，只需要一根普通的安卓MicroUSB数据线即可完成你的设计。

### STM32下位机

- 基于uFUN开发板的STM32程序
- 串口驱动，串口中断，数据的接收和解析。
- 定时器的使用，PWM方式驱动RGB

![](https://wcc-blog.oss-cn-beijing.aliyuncs.com/img/uFUN2_0/正面1.jpeg)

### Qt上位机

基于Qt 5.8.0开发，采用串口协议和uFUN开发板进行通讯，数据协议固定，串口波特115200，可自定义RGB的亮度，可通过调色板来选择任意颜色，直接双击运行，无需安装。

- 串口的使用，串口的搜索，串口参数的设置
- 串口的打开关闭，串口数据的发送和接收
- 串口自定义波特率的实现
- 滑动条的使用，滑动条值的获取和设置，调色板RGB颜色值的获取
- 按钮的触发，信号与槽
- 多窗口的打开和关闭
- 文字超链接的使用，图片的显示

![](https://wcc-blog.oss-cn-beijing.aliyuncs.com/img/RGB_Control_PC.jpg)

### 我的评测文章

- 2.0版本开箱评测：[千呼万唤始出来——uFUN开发板2.0开箱评测](http://www.wangchaochao.top/2019/10/15/uFUN2-0/) 
- 1.0版本开箱评测：[【UFUN开发板评测】小巧而不失精致，简单而不失内涵——uFun开发板开箱爆照](http://www.wangchaochao.top/2019/03/09/uFun-1/)
- uFUN系列评测文章： [uFUN开发板评测](http://www.wangchaochao.top/tags/#uFUN开发板评测) 

### 关于我

- 我的博客： http://www.wangchaochao.top
- Gitee： https://gitee.com/whik 
- Github： https://github.com/whik 

![](https://wcc-blog.oss-cn-beijing.aliyuncs.com/img/about_me.jpg)

