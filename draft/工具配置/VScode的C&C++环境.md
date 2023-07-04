# VScode的C&C++环境配置

```json
//launch.json
{
    "version": "0.2.0",
    "configurations": [
        {
        "name": "gcc", // 配置名称，将会在启动配置的下拉菜单中显示
        "type": "cppdbg", // 配置类型，cppdbg对应cpptools提供的调试功能；可以认为此处只能是cppdbg
        "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
        "program": "${fileDirname}/${fileBasenameNoExtension}.exe", // 将要进行调试的程序的路径
        "args": [], // 程序调试时传递给程序的命令行参数，一般设为空即可
        "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，相当于在main上打断点
        "cwd": "${workspaceFolder}", // 调试程序时的工作目录，此为工作区文件夹；改成${fileDirname}可变为文件所在目录
        "environment": [], // 环境变量
        "externalConsole": true, // 为true时使用单独的cmd窗口，与其它IDE一致；18年10月后设为false可调用VSC内置终端
        "internalConsoleOptions": "neverOpen", // 如果不设为neverOpen，调试时会跳到“调试控制台”选项卡，你应该不需要对gdb手动输命令吧？
        "MIMode": "gdb", // 指定连接的调试器，可以为gdb或lldb。但我没试过lldb
        "miDebuggerPath": "gdb.exe", // 调试器路径，Windows下后缀不能省略，Linux下则不要
        "setupCommands": [
            { // 模板自带，好像可以更好地显示STL容器的内容，具体作用自行Google
                "description": "Enable pretty-printing for gdb",
                "text": "-enable-pretty-printing",
                "ignoreFailures": false
            }
        ],
        "preLaunchTask": "gcc" // 调试会话开始前执行的任务，一般为编译程序。与tasks.json的label相对应
    },
    {
        "name": "g++",
        "type": "cppdbg",
        "request": "launch",
        "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
        "args": [],
        "stopAtEntry": false,
        "cwd": "${workspaceFolder}",
        "environment": [],
        "externalConsole": true,
        "internalConsoleOptions": "neverOpen",
        "MIMode": "gdb",
        "miDebuggerPath": "gdb.exe",
        "setupCommands": [
            { 
                "description": "Enable pretty-printing for gdb",
                "text": "-enable-pretty-printing",
                "ignoreFailures": false
            }
        ],
        "preLaunchTask": "g++"
    }]
}
```

//tasks.json

```json
{
    "version": "2.0.0",
    "tasks": [{
        "label": "gcc", // 任务名称，与launch.json的preLaunchTask相对应
        "command": "gcc",   // 要使用的编译器，C++用g++
        "args": [
            "${file}",
            "-o",    // 指定输出文件名，不加该参数则默认输出a.exe，Linux下默认a.out
            "${fileDirname}/${fileBasenameNoExtension}.exe",
            "-g",    // 生成和调试有关的信息
            "-Wall", // 开启额外警告
            "-static-libgcc",     // 静态链接libgcc，一般都会加上
            "-fexec-charset=GBK", // 生成的程序使用GBK编码，不加这一条会导致Win下输出中文乱码
            // "-std=c11", // C++最新标准为c++17，或根据自己的需要进行修改
        ], // 编译的命令，其实相当于VSC帮你在终端中输了这些东西
        "type": "process", // process是vsc把预定义变量和转义解析后直接全部传给command；shell相当于先打开shell再输入命令，所以args还会经过shell再解析一遍
        "group": {
            "kind": "build",
            "isDefault": true // 不为true时ctrl shift B就要手动选择了
        },
        "presentation": {
            "echo": true,
            "reveal": "always", // 执行任务时是否跳转到终端面板，可以为always，silent，never。具体参见VSC的文档
            "focus": false,     // 设为true后可以使执行task时焦点聚集在终端，但对编译C/C++来说，设为true没有意义
            "panel": "shared"   // 不同的文件的编译信息共享一个终端面板
        },
        // "problemMatcher":"$gcc" // 此选项可以捕捉编译时终端里的报错信息；但因为有Lint，再开这个可能有双重报错
    },
    {
        "label": "g++",
        "command": "g++",
        "args": [
            "${file}",
            "-o",
            "${fileDirname}/${fileBasenameNoExtension}.exe",
            "-g",
            "-Wall",
            "-static-libgcc",
            "-fexec-charset=GBK",
        ],
        "type": "process",
        "group": {
            "kind": "build",
            "isDefault": true
        },
        "presentation": {
            "echo": true,
            "reveal": "always",
            "focus": false,
            "panel": "shared"  
        },
    }]
}
```
