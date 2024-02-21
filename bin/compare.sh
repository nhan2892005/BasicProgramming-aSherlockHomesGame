#!/bin/bash

dir1="$1"
dir2="$2"
found_difference=false

# Kiểm tra xem thư mục có tồn tại không
if [ ! -d "$dir1" ]; then
    echo "Error: Directory '$dir1' does not exist."
    exit 1
fi

if [ ! -d "$dir2" ]; then
    echo "Error: Directory '$dir2' does not exist."
    exit 1
fi

# Lấy danh sách tất cả các file có cùng tên trong hai thư mục
files=$(comm -12 <(cd "$dir1" && ls -1) <(cd "$dir2" && ls -1))

# So sánh các file có cùng tên trong hai thư mục
for file in $files; do
    file1="$dir1/$file"
    file2="$dir2/$file"
    
    if [ -f "$file1" ] && [ -f "$file2" ]; then
        # So sánh nội dung của hai file
        if cmp -s "$file1" "$file2"; then
            echo "$file"  # In ra tên file nếu giống nhau
        else
            echo "Files '$file1' is different."
            found_difference=true
            break  # Dừng lại nếu có file khác nhau
        fi
    fi
done

# Kiểm tra nếu không tìm thấy bất kỳ file nào khác nhau
if ! $found_difference; then
    echo "All files are identical."
fi
