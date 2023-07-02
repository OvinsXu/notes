import os

# 生成目录
def generate_summary(directory_path, level=0):
    if not os.path.isdir(directory_path):
        return

    indent = "  " * level
    dirs = []
    files = []

    # 遍历目录，将文件和子目录分别存储到对应的列表中
    for entry in os.scandir(directory_path):
        if entry.is_file():
            files.append(entry.name)
        elif entry.is_dir():
            dirs.append(entry.name)

    # 当前目录下的文件
    for file_name in sorted(files):
        if file_name != "SUMMARY.md":
            chapter_title = os.path.splitext(file_name)[0]  #去除扩展名获取章节标题
            chapter_path = os.path.join(directory_path, file_name) 
            relative_path = os.path.relpath(chapter_path, root_directory)
            link = f"- [{chapter_title}]({relative_path})\n"
            with open("./src/SUMMARY.md", "a") as summary_file:
                summary_file.write(f"{indent}{link}")

    # 递归子目录
    for i, dir_name in enumerate(sorted(dirs)):
        subdirectory_path = os.path.join(directory_path, dir_name)
        with open("./src/SUMMARY.md", "a") as summary_file:
            summary_file.write(f"{indent}- [{dir_name}]()\n")
        generate_summary(subdirectory_path,level+1)

# 指定包含章节的文件夹路径
root_directory = "./src" 
summary_path = root_directory+"/SUMMARY.md"

#先把SUMMARY.md删除
if os.path.exists(summary_path):
    try:
        os.remove(summary_path)
        print("文件删除成功")
    except OSError as e:
        print(f"文件删除失败: {e}")

# 生成新的
with open("./src/SUMMARY.md", "w") as summary_file:
        summary_file.write("# 目录\n\n[博客目录](SUMMARY.md)\n\n[草稿](https://github.com/OvinsXu/notes/tree/master/draft)\n\n---\n\n")

generate_summary(root_directory)