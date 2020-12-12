Page({
    data: {
        delBtnWidth: 185,
        years: [],
        months: [],
        days: [],
        year: 0,
        month: 0,
        date: ['日', '一', '二', '三', '四', '五', '六'],
        dateArr: [],
        isToday: 0,
        isTodayWeek: false,
        todayIndex: 0,
        //isShow:false,
        text:"",
        delBtnWidth: 150, //删除按钮宽度单位（rpx）

        //展示
        isIndex:"flex",
        isPlanShow:"hide",
        isCalShow:"hide",
        isStarTime:"hide",
        isEndTime:"hide",
    
    },

    

    //取消按钮
    // no: function () {
    //     //this.isShow = !this.isShow;
    //     //let flag = !this.isShow;
    //     this.setData({
    //         isShow: false
    //     })
    // },
    // //确认按钮
    // yes: function () {
    //     //this.isShow = !this.isShow;
    //     //let flag = !this.isShow;
    //     this.setData({
    //         isShow: false
    //     })
    //     var data = this.date0+"-"+this.date1;
    //     wx.setStorageSync({
    //         key:"1",
    //         data:data
    //     })
    //     wx.getStorage({
    //         key: "1",
    //         success: function(res) {

    //         },
    //     })
    // },
    //新建日程按钮
    // createCalendar:function(){
    //     //this.isShow = !this.isShow;
    //     //let flag = !this.isShow;
    //     this.setData({
    //         isShow:true
    //     })
    // },

    //新建计划
    createPlan:function(){
        this.setData({
            isPlanShow:"flex",
            isIndex:"hide"
        })
    },
    //记录输入框内容
    input: function(e) {
        if (e.detail.value) {
            var flag = true;
        } else {
            var flag = false;
        }
        this.setData({
            isNULL:flag,
            input: [{
                txtStyle: "",
                txt: e.detail.value
            }, ]

        })
        //console.log(this.data.input.txt);
    },
    yes: function() {
        if (this.data.isNULL) {
            var list = this.data.list;
            list = list.concat(this.data.input);
            this.setData({
                list: list,
                text:"",
                input: [{
                    txtStyle: "",
                    txt:""
                },]
            })
        }
        
    },

    //新建日程
    createCalendar:function(){
        this.setData({
            isCalShow:"show",
            isIndex:"hide"
        })
    },
    //选择开始日期
    selStarDate:function(){
        this.setData({
            isStarDate: "flex"
        })
        
    },
    //选择开始时间
    selStarTime:function(){
        this.setData({
            isStarTime: "flex"
        })
        
    }, 
    //记录开始时间
    bindDateChange0(e) {
        this.setData({
            date0: e.detail.value
        })
    },
    //记录结束时间
    bindDateChange1(e) {
        console.log('picker发送选择改变，携带值为', e.detail.value)
        this.setData({
            date1: e.detail.value
        })
    },
    //选择结束日期
    //选择结束时间
    onLoad: function() {
        let now = new Date();
        let year = now.getFullYear();
        let month = now.getMonth() + 1;
        this.dateInit();
        this.setData({
            year: year,
            month: month,
            isToday: '' + year + month + now.getDate()
        });
        this.initEleWidth();
        this.tempData();
    },
    touchS: function(e) {
        if (e.touches.length == 1) {
            this.setData({
                //设置触摸起始点水平方向位置
                startX: e.touches[0].clientX
            });
        }
    },
    touchM: function(e) {
        if (e.touches.length == 1) {
            //手指移动时水平方向位置
            var moveX = e.touches[0].clientX;
            //手指起始点位置与移动期间的差值
            var disX = this.data.startX - moveX;
            var delBtnWidth = this.data.delBtnWidth;
            var txtStyle = "";
            if (disX == 0 || disX < 0) { //如果移动距离小于等于0，文本层位置不变
                txtStyle = "left:0px";
            } else if (disX > 0) { //移动距离大于0，文本层left值等于手指移动距离
                txtStyle = "left:-" + disX + "px";
                if (disX >= delBtnWidth) {
                    //控制手指移动距离最大值为删除按钮的宽度
                    txtStyle = "left:-" + delBtnWidth + "px";
                }
            }
            //获取手指触摸的是哪一项
            var index = e.target.dataset.index;
            var list = this.data.list;
            if (index >= 0) {
                list[index].txtStyle = txtStyle;
                //更新列表的状态
                this.setData({
                    list: list
                });
            }
        }
    },

    touchE: function(e) {
        if (e.changedTouches.length == 1) {
            //手指移动结束后水平位置
            var endX = e.changedTouches[0].clientX;
            //触摸开始与结束，手指移动的距离
            var disX = this.data.startX - endX;
            var delBtnWidth = this.data.delBtnWidth;
            //如果距离小于删除按钮的1/2，不显示删除按钮
            var txtStyle = disX > delBtnWidth / 2 ? "left:-" + delBtnWidth + "px" : "left:0px";
            //获取手指触摸的是哪一项
            var index = e.target.dataset.index;
            var list = this.data.list;
            console.log(e);
            if (index >= 0) {
                list[index].txtStyle = txtStyle;
                //更新列表的状态
                this.setData({
                    list: list
                });
            }
        }
    },
    //获取元素自适应后的实际宽度
    getEleWidth: function(w) {
        var real = 0;
        try {
            var res = wx.getSystemInfoSync().windowWidth;
            var scale = (750 / 2) / (w / 2); //以宽度750px设计稿做宽度的自适应
            // console.log(scale);
            real = Math.floor(res / scale);
            return real;
        } catch (e) {
            return false;
            // Do something when catch error
        }
    },
    initEleWidth: function() {
        var delBtnWidth = this.getEleWidth(this.data.delBtnWidth);
        this.setData({
            delBtnWidth: delBtnWidth
        });
    },
    //点击删除按钮事件
    delItem: function(e) {
        //获取列表中要删除项的下标
        var index = e.target.dataset.index;
        var list = this.data.list;
        //移除列表中下标为index的项
        list.splice(index, 1);
        //更新列表的状态
        this.setData({
            list: list
        });
    },
    dateInit: function(setYear, setMonth) {
        //全部时间的月份都是按0~11基准，显示月份才+1
        let dateArr = []; //需要遍历的日历数组数据
        let arrLen = 0; //dateArr的数组长度
        let now = setYear ? new Date(setYear, setMonth) : new Date();
        let year = setYear || now.getFullYear();
        let nextYear = 0;
        let month = setMonth || now.getMonth(); //没有+1方便后面计算当月总天数
        let nextMonth = (month + 1) > 11 ? 1 : (month + 1);
        let startWeek = new Date(year + ',' + (month + 1) + ',' + 1).getDay(); //目标月1号对应的星期
        let dayNums = new Date(year, nextMonth, 0).getDate(); //获取目标月有多少天
        let obj = {};
        let num = 0;

        if (month + 1 > 11) {
            nextYear = year + 1;
            dayNums = new Date(nextYear, nextMonth, 0).getDate();

        }
        arrLen = startWeek + dayNums;
        for (let i = 0; i < arrLen; i++) {
            if (i >= startWeek) {
                num = i - startWeek + 1;
                obj = {
                    isToday: '' + year + (month + 1) + num,
                    dateNum: num,
                    weight: 5

                }

            } else {
                obj = {};

            }
            dateArr[i] = obj;

        }
        this.setData({
            dateArr: dateArr

        })

        let nowDate = new Date();
        let nowYear = nowDate.getFullYear();
        let nowMonth = nowDate.getMonth() + 1;
        let nowWeek = nowDate.getDay();
        let getYear = setYear || nowYear;
        let getMonth = setMonth >= 0 ? (setMonth + 1) : nowMonth;

        if (nowYear == getYear && nowMonth == getMonth) {
            this.setData({
                isTodayWeek: true,
                todayIndex: nowWeek
            })

        } else {
            this.setData({
                isTodayWeek: false,
                todayIndex: -1
            })
        }

    },

    lastMonth: function() {
        //全部时间的月份都是按0~11基准，显示月份才+1
        let year = this.data.month - 2 < 0 ? this.data.year - 1 : this.data.year;
        let month = this.data.month - 2 < 0 ? 11 : this.data.month - 2;
        this.setData({
            year: year,
            month: (month + 1)
        })
        this.dateInit(year, month);
    },
    nextMonth: function() {
        //全部时间的月份都是按0~11基准，显示月份才+1
        let year = this.data.month > 11 ? this.data.year + 1 : this.data.year;
        let month = this.data.month > 11 ? 0 : this.data.month;
        this.setData({
            year: year,
            month: (month + 1)
        })
        this.dateInit(year, month);
    },
    tempData: function() {
        var list = [{
            txtStyle: "",

            txt: "向左滑动可以删除"
        }, ];

        this.setData({
            list: list
        });
    }

})