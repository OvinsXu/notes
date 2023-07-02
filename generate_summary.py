import os

# 删除目录文件
def delete_summary(summary_path):
    if os.path.exists(summary_path):
        try:
            os.remove(summary_path)
            print("文件删除成功")
        except OSError as e:
            print(f"文件删除失败: {e}")

# 生成目录
def generate_summary(directory_path, summary_path,level=0):
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
        if "SUMMARY.md" not in file_name:
            chapter_title = os.path.splitext(file_name)[0]  #去除扩展名获取章节标题
            chapter_path = os.path.join(directory_path, file_name) 
            
            if "draft" in chapter_path:
                relative_path = os.path.relpath(chapter_path, draft_directory)
                link = f"- [{chapter_title}](https://github.com/OvinsXu/notes/blob/master/draft/{relative_path})\n"
            else:
                relative_path = os.path.relpath(chapter_path, root_directory)
                link = f"- [{chapter_title}]({relative_path})\n"
            with open(summary_path, "a") as summary_file:
                summary_file.write(f"{indent}{link}")

    # 递归子目录
    for i, dir_name in enumerate(sorted(dirs)):
        subdirectory_path = os.path.join(directory_path, dir_name)

        if "draft" in subdirectory_path:
            relative_path = os.path.relpath(subdirectory_path, draft_directory)
            link = f"https://github.com/OvinsXu/notes/blob/master/draft/{relative_path}"
        else:
            link = ""

        with open(summary_path, "a") as summary_file:
            summary_file.write(f"{indent}- [{dir_name}]({link})\n")
        generate_summary(subdirectory_path,summary_path,level+1)

# 正文和草稿的目录文件
root_directory = "./src"
summary_path = root_directory+"/SUMMARY.md"

draft_directory = "./draft"
draft_summary_path = root_directory+"/DRAFT_SUMMARY.md"

delete_summary(summary_path)
delete_summary(draft_summary_path)

# 生成新的
with open(summary_path, "w") as summary_file:
        summary_file.write("# 目录\n\n[博客目录](SUMMARY.md)\n\n[草稿目录](./DRAFT_SUMMARY.md)\n\n---\n\n")
with open(draft_summary_path, "w") as summary_file:
        summary_file.write("# 目录\n\n[博客目录](SUMMARY.md)\n\n[草稿目录](./DRAFT_SUMMARY.md)\n\n---\n\n")

generate_summary(root_directory,summary_path)
generate_summary(draft_directory,draft_summary_path)