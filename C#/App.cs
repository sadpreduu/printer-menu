// Prototipo do codigo em C# 

using System;
using System.IO;

class AtualizarCaminhoVideo
{
    static void Main()
    {
        string filePath = @"Caminho\Para\Seu\Arquivo.bat";
        string newVideoPath = @"C:\Caminho\Para\SeuNovoVideo.mp4";

        try
        {
            AtualizarCaminhoDoVideo(filePath, newVideoPath);
            Console.WriteLine("Caminho do vídeo atualizado com sucesso no arquivo BAT.");
        }
        catch (IOException e)
        {
            Console.Error.WriteLine($"Erro: {e.Message}");
        }
    }

    static void AtualizarCaminhoDoVideo(string filePath, string newVideoPath)
    {
        string[] lines = File.ReadAllLines(filePath);

        for (int i = 0; i < lines.Length; i++)
        {
            if (lines[i].Contains("set \"videoPath="))
            {
                lines[i] = $"set \"videoPath={newVideoPath}\"";
            }
        }

        File.WriteAllLines("temp.bat", lines);

        // Renomeia o arquivo temporário para o arquivo original
        File.Move("temp.bat", filePath);
    }
}
