#現在のファイル名
old_prefix="syuhou05"

# 新規ファイル名
new_prefix="20240527"

for file in ${old_prefix}.*; do
    mv "$file" "${new_prefix}.${file##*.}"
done
