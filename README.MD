# Printer Menu

This project is an early prototype for an printer manager system designed to manege automation printers on a Warehouse. 


# Test 

First of all we need to understand what is the problem and how do we want to solve it. To test a C++ program that opens, reads and edits a BAT (Batch) file I created this simple .bat file to play a video. 

```Shell
@echo off

rem Caminho para o executável do VLC
set "vlcPath=C:\Program Files\VideoLAN\VLC\vlc.exe"

rem Caminho para o vídeo
set "videoPath=C:\Caminho\Para\SeuVideo.mp4"

rem Abre o vídeo no VLC
start "" "%vlcPath%" "%videoPath%"
```
First I set the player address and the video address as varibles:

>vlcPath

>videoPath

so when the C++ script runs it will be able to change both the player and the video separately.

Falando um pouco do script de C++, ele abre o arquivo e faz a troca do caminho pelo o que estiver dentro da variave ` newVideoPath ` e ele faz isso com esse bloco de codigo a baixo:

```cpp
    size_t pos = content.find("set \"videoPath=");
    if (pos != std::string::npos) {
        size_t endPos = content.find("\"", pos + 15); // 15 é o comprimento de "set \"videoPath="
        if (endPos != std::string::npos) {
            content.replace(pos + 15, endPos - (pos + 15), newVideoPath);
        }
    }
```

Depois disso ele fecha o arquivo e abre ele em modo de leitura, ele faz isso para validar se a inserção deu certo e não quebrou a instrução subistituida dentro do arquivo BAT. 

# Problemas de Compatibilidade

Podem haver problemas de compatibilidade no momemnto de rodar esse programa e isso se deve a escolha de lang para esse projeto que foi a C++, ela precisa de uns recursos e principalmente de algumas DLL no sistema para poder rodar corretamente. 

# Testes em JAVA 

Por causa dos problemas de compatibilidade do C++ decidi re-escrever o programa utilizando java e a JVM para rodar o programa. Também pensei que com java teria opções de interface grafica mais bonitas. 

# Testes em C# 