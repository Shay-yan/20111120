# 🐾 动物收容所管理系统（Animal Shelter Management System）
 
**当前版本：** `v0.1.0` — *公开预览版*  
**语言：** C++17  
**平台：** Windows

---

## 📌 项目简介
一个极简的终端式“动物收容所”模拟程序，支持  
- 🐱 创建/管理动物档案  
- 🍖 投喂、🎯 陪玩实时影响饱食度与心情  
- 💾 本地文件持久化，断档即恢复  

---

## 🚀 快速开始

### 1️⃣ 克隆源码
```bash
git clone https://github.com/Shay_yan/animal-shelter.git
cd animal-shelter
```

### 2️⃣ 编译
```bash
g++ Pet_accommodation.cpp -std=c++17 -o shelter
```

### 3️⃣ 运行
```bash
./shelter
```

---

## 🕹️ 使用指南

| 主菜单 | 功能 |
|---|---|
| `1` | 添加新动物（输入名字即可） |
| `2` | 查看所有动物并进入互动子菜单 |
| `3` | 退出程序（自动保存） |

> 在“查看”界面输入动物编号后  
> `F` 投喂（饱食度+2） `K` 陪玩（心情+2）

---

## 📂 项目结构
```
animal-shelter/
├── Pet_accommodation.cpp          # 主程序
├── Pet_accommodation_class_animal.hpp
├── README.md
└── animal.txt (运行时自动生成)    # 数据文件
```

---

## 🛠️ 技术栈
- **语言**：C++17  
- **构建**：单文件直接编译  
- **数据存储**：纯文本（未来版本计划迁移至 JSON）

---

## 🗺️ 路线图
| 版本 | 计划功能 |
|---|---|
| v0.2.0 | 动物删除/改名 |
| v0.3.0 | 动物分类（猫/狗/兔…）、年龄、性别字段 |
| v1.0.0 | 稳定 API、单元测试、跨平台 CI |

---

## 📄 许可证
MIT License — 详见 [LICENSE](LICENSE)。

---

> 喜欢就给个 ⭐️ 吧！  
> 遇到问题欢迎在 [Issues](https://github.com/<your-org>/animal-shelter/issues) 留言。
