# MAC

```bash
# 1. 编译器 — 装 Xcode 命令行工具(通常已有,没有会弹窗引导)
xcode-select --install
g++ --version    # 有输出就行

# 2. 字体(可选,不装会回退到 Menlo)
brew install --cask font-jetbrains-mono
```

- 然后用 VS Code 打开 XCPC 文件夹 → 右下角弹推荐 → 点"全部安装" → 主题提示点允许 → 重载窗口

- Cmd+Shift+B 编译; F5 调试(走 CodeLLDB); CTLR+OPT+N 使用 Code Runner 运行

- 如果没弹推荐提示，Cmd+Shift+P 输入 Extensions: Show Recommended Extensions 手动调出来


# WIN

## 1.装编译器

最省事的是 winlibs 的免安装包：去 winlibs.com 下 UCRT runtime 的 Win64 压缩包，解压到比如 C:\mingw64，然后把 C:\mingw64\bin 加进系统环境变量 PATH。


## 2.验证

新开一个 PowerShell（PATH 改动要新窗口才生效）：

```powershell
g++ --version
gdb --version
```

两个都有输出才算成功。gdb 尤其要确认——winlibs 的包自带，但有些精简版 MinGW 不带，那样 F5 调试会失败。

## 3.打开文件夹装扩展

同 Mac，但 vadimcn.vscode-lldb 在 Windows 上用不到（你的 launch.json 里 Windows 走的是 cppdbg），装了也无妨，不装就跳过

## 4.调试时选对配置

F5 之前，在调试面板顶部的下拉框里选 "Debug (Windows / GDB)"。选错了会报 lldb 找不到

bits/stdc++.h 你不用管——MinGW 用 libstdc++，自带这个头。你的 bits/ 目录在搜索顺序里排前面，会优先用你那份；就算 bits/ 没跟着拷过去，也会落到 MinGW 自带的那份。两种情况都能编译。