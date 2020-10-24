gnome-terminal --window -e 'bash -c "service privoxy start"' \
--tab -e 'bash -c " export http_proxy='http://localhost:8118'"' \
--tab -e 'bash -c " export https_proxy='http://localhost:8118'"' \ 
