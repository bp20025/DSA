#現在のファイル名
old_prefix="syuhou07"

# 新規ファイル名
new_prefix="20240617"

for file in ${old_prefix}.*; do
    mv "$file" "${new_prefix}.${file##*.}"
done
