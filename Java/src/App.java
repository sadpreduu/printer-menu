package Java.src;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class App {
    public static void main(String[] args) {
        String filePath = "Caminho\\Para\\Seu\\Arquivo.bat";
        String newVideoPath = "C:\\Caminho\\Para\\SeuNovoVideo.mp4";

        try {
            updateVideoPath(filePath, newVideoPath);
            System.out.println("Caminho do vídeo atualizado com sucesso no arquivo BAT.");
        } catch (IOException e) {
            System.err.println("Erro: " + e.getMessage());
        }
    }

    private static void updateVideoPath(String filePath, String newVideoPath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        FileWriter writer = new FileWriter("temp.bat");

        String line;
        while ((line = reader.readLine()) != null) {
            if (line.contains("set \"videoPath=")) {
                line = "set \"videoPath=" + newVideoPath + "\"";
            }
            writer.write(line + System.lineSeparator());
        }

        reader.close();
        writer.close();

        // Renomeia o arquivo temporário para o arquivo original
        java.nio.file.Files.move(java.nio.file.Paths.get("temp.bat"),
                                 java.nio.file.Paths.get(filePath),
                                 java.nio.file.StandardCopyOption.REPLACE_EXISTING);
    }
}

