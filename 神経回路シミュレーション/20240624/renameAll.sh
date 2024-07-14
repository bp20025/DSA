#現在のファイル名
old_prefix="20240617"

# 新規ファイル名
new_prefix="20240624"

for file in ${old_prefix}.*; do
    mv "$file" "${new_prefix}.${file##*.}"
done
