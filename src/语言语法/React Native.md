# React Native

> 尝试学习了一阵，决定还是想先学习原生开发，以后有空再来学

## 一，开发环境配置

安装环境：`npm install -g react-native-cli`  
升级环境：`npm update -g react-native-cli`  
创建项目：`react-native init 项目名称`  
编译运行：`react-native run-android`  

## 二,布局

一，flex布局  
    1.flexDirction  设置主轴方向  
        row(->)/column（默认）  
    2.justifyContent    主轴对齐方式  
        flex-start/end,center,space-between/around(两端，两盒 子之间间隔相等/盒子两边间隔相等)  
    3.alignItems        侧轴对齐方式  
        flex-start/end，center，baseline（第一行文字下线的对齐），stretch（没设值/auto，则占满）  
    4.flexWrap      是否换行  
        nowrap，wrap，wrap-reverse  
    5.alignSelf     独立于父元素  
        flex-start/end，center，baseline，stretch  
    大小：按比例  
二，获取屏幕分辨率  
    宽：Dimension.get('window').width  
    高：Dimension.get('window').height  
    分辨率：Dimension.get('window').scale  

### 三，控件

一，image
    实例：

```jsx
    import ... from ...
    var allPack = [];
    for(var i = 0;i < allPack.data.lenght;i++){
        var pack = allPack.data[i];
        allPack.push(
            <View key = {i}>
                <Image source = {{uri:pack.icon}}/>
                <Text>
                    {pack.title}
                </Text>
            </View>
        )
    }
```

二，TextInput  
    `value`设置默认值  
    `onChangeText`监听输入  
    `keyboardType`键盘类型  
    `multiline`多行  
    `password`密码,password={true}  
    `placeholder`占位文字  
    `placeholderTextColor`占位符的颜色  
    `autoCapitalize`。。。  
三，Touchable  
    1.TouchableOpacity降低透明度  
        TouchableHighlight···  
    2.点击onPress  
        按下onPressIn  
        抬起onpressOut  
        长按onLongPress  
四，ScrollView  
1.`contentContainerStyle`  
2.`horizontal`水平方向  
3.`showHorizontalScrollIndicator`水平滚动条  
4.`pagingEnadled`自动分页  
五，ListView  

### 四，生命周期
