#現在のファイル名
old_prefix="2024"

# 新規ファイル名
new_prefix="20240701"

for file in ${old_prefix}.*; do
    mv "$file" "${new_prefix}.${file##*.}"
done
