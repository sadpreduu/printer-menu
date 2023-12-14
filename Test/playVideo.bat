@echo off

rem Caminho para o executável do VLC
set "vlcPath=C:\Program Files\VideoLAN\VLC\vlc.exe"

rem Caminho para o vídeo
set "videoPath=C:\Caminho\Para\SeuVideo.mp4"

rem Abre o vídeo no VLC
start "" "%vlcPath%" "%videoPath%"