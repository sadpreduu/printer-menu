//Rascunho Numero Uno, tentando editar o caminho do video com codigo C++

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Caminho para o arquivo bat
    std::string batFilePath = "C:\\ImagensRei\\Selecionar_Video.bat";

    // Novo caminho para o vídeo
    std::string newVideoPath = "C:\\ImagensRei\\NovoVideo.mp4";

    // Abrir o arquivo bat em modo de leitura
    std::ifstream batFile(batFilePath);

    // Verificar se o arquivo foi aberto com sucesso
    if (!batFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << batFilePath << std::endl;
        return 1; // Encerrar o programa com erro
    }

    // Ler o conteúdo do arquivo para uma string
    std::string content((std::istreambuf_iterator<char>(batFile)),
                         std::istreambuf_iterator<char>());

    // Encontrar e substituir o caminho do vídeo
    size_t pos = content.find("set \"videoPath=");
    if (pos != std::string::npos) {
        size_t endPos = content.find("\"", pos + 15); // 15 é o comprimento de "set \"videoPath="
        if (endPos != std::string::npos) {
            content.replace(pos + 15, endPos - (pos + 15), newVideoPath);
        }
    }

    // Fechar o arquivo
    batFile.close();

    // Abrir o arquivo bat em modo de escrita
    std::ofstream newBatFile(batFilePath);

    // Verificar se o arquivo foi aberto com sucesso
    if (!newBatFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << batFilePath << " para escrita" << std::endl;
        return 1; // Encerrar o programa com erro
    }

    // Escrever o conteúdo modificado de volta no arquivo
    newBatFile << content;

    // Fechar o arquivo
    newBatFile.close();

    std::cout << "Arquivo BAT modificado com sucesso." << std::endl;

    return 0; // Encerrar o programa sem erros
}