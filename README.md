<h1 align="center"> TUI JSON数据结构的解析和创建 </h1>

## 描述
TUI *V2.1* 以上版本支持对`json`数据结构的解析和创建，tjson对开源的cjson进行了优化，支持带注释的json文件（如：`/*  */`和`//`），整形数据支持十六进制的表达（如：0x123ABC）。<br>
`TUISYS/json_demo`仓库只提供了头文件接口和测试demo，实际应用要结合`TUISYS/tui_project`仓库里面的tui库文件。
直接将`tjson.h`放进`TUISYS/tui_project/includes`，然后应用就可以调用相关函数了。

## `json`文件解析
`test.c`中`tui_json_read_test()`函数，实现了读取`test.json`数据，详细细节参考对应的demo用例

## `json`文件创建
`test.c`中`tui_json_write_test()`函数，实现了创建`json`数据的字符串，并且打印出来，详细细节参考对应的demo用例
