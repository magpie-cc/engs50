{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "provenance": [],
      "include_colab_link": true
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "view-in-github",
        "colab_type": "text"
      },
      "source": [
        "<a href=\"https://colab.research.google.com/github/magpie-cc/engs50/blob/main/src/filter.ino\" target=\"_parent\"><img src=\"https://colab.research.google.com/assets/colab-badge.svg\" alt=\"Open In Colab\"/></a>"
      ]
    },
    {
      "cell_type": "code",
      "execution_count": null,
      "metadata": {
        "colab": {
          "base_uri": "https://localhost:8080/",
          "height": 110
        },
        "id": "g3P5oIZU8DAG",
        "outputId": "1588bb24-5b54-423a-c4e4-596e2bbc6b74"
      },
      "outputs": [
        {
          "output_type": "error",
          "ename": "SyntaxError",
          "evalue": "unterminated string literal (detected at line 102) (ipython-input-2978794761.py, line 102)",
          "traceback": [
            "\u001b[0;36m  File \u001b[0;32m\"/tmp/ipython-input-2978794761.py\"\u001b[0;36m, line \u001b[0;32m102\u001b[0m\n\u001b[0;31m    Serial.print(\"  -  \"); // don't print \"0.00\"\u001b[0m\n\u001b[0m                                 ^\u001b[0m\n\u001b[0;31mSyntaxError\u001b[0m\u001b[0;31m:\u001b[0m unterminated string literal (detected at line 102)\n"
          ]
        }
      ],
      "source": [
        "// =========================================================================\n",
        "// Htotal_v7.ino\n",
        "//\n",
        "// Testing on A0 instead of A2 to check for pin-specific noise.\n",
        "// Double-cascaded biquad filter + pot volume control.\n",
        "// =========================================================================\n",
        "\n",
        "#include <Audio.h>\n",
        "#include <Wire.h>\n",
        "#include <SPI.h>\n",
        "\n",
        "// --- Pot settings --------------------------------------------------------\n",
        "#define POT_PIN          A4\n",
        "#define VOL_MIN          0.001\n",
        "#define VOL_MAX          0.5\n",
        "#define POT_INTERVAL_MS  50\n",
        "#define POT_DEADBAND     10\n",
        "#define POT_SMOOTH       0.3\n",
        "\n",
        "// --- Audio objects -------------------------------------------------------\n",
        "AudioInputAnalog         in(A2);\n",
        "AudioFilterBiquad        htotal1;\n",
        "AudioFilterBiquad        htotal2;\n",
        "AudioOutputI2S           out;\n",
        "AudioControlSGTL5000     audioShield;\n",
        "\n",
        "// --- Signal chain --------------------------------------------------------\n",
        "AudioConnection c1(in,      0, htotal1, 0);\n",
        "AudioConnection c2(htotal1, 0, htotal2, 0);\n",
        "AudioConnection c3(htotal2, 0, out,     0);\n",
        "AudioConnection c4(htotal2, 0, out,     1);\n",
        "\n",
        "// --- State ---------------------------------------------------------------\n",
        "float    smoothedPot = 409.0;\n",
        "float    lastSentPot = -99.0;\n",
        "uint32_t lastPotRead = 0;\n",
        "\n",
        "// =========================================================================\n",
        "void setup() {\n",
        "  pinMode(POT_PIN, INPUT);\n",
        "\n",
        "  AudioMemory(30);\n",
        "\n",
        "  audioShield.enable();\n",
        "  audioShield.volume(0.5);\n",
        "\n",
        "  //                              b0              b1              b2              a1              a2\n",
        "  double s0[] = {  0.4031285387, -0.4892925572,  0.1958418664, -0.2318435712,  0.0000000000 };\n",
        "  double s1[] = {  1.0000000000, -1.2137300050,  0.4857940360, -1.5265360471,  0.5897956163 };\n",
        "  double s2[] = {  1.0000000000, -1.2137491504,  0.4858061508, -1.0847847561,  0.1977489355 };\n",
        "  double s3[] = {  1.0000000000, -0.7093023256,  0.0000000000, -1.7349880661,  0.8068858754 };\n",
        "\n",
        "  htotal1.setCoefficients(0, s0);  htotal2.setCoefficients(0, s0);\n",
        "  htotal1.setCoefficients(1, s1);  htotal2.setCoefficients(1, s1);\n",
        "  htotal1.setCoefficients(2, s2);  htotal2.setCoefficients(2, s2);\n",
        "  htotal1.setCoefficients(3, s3);  htotal2.setCoefficients(3, s3);\n",
        "}\n",
        "\n",
        "// =========================================================================\n",
        "void loop() {\n",
        "  if (millis() - lastPotRead >= POT_INTERVAL_MS) {\n",
        "    lastPotRead = millis();\n",
        "\n",
        "    float raw   = analogRead(POT_PIN);\n",
        "    smoothedPot = smoothedPot + POT_SMOOTH * (raw - smoothedPot);\n",
        "\n",
        "    if (abs(smoothedPot - lastSentPot) > POT_DEADBAND) {\n",
        "      float linear = smoothedPot / 1023.0;\n",
        "      float vol    = VOL_MIN * pow(VOL_MAX / VOL_MIN, linear);\n",
        "      audioShield.volume(vol);\n",
        "      lastSentPot  = smoothedPot;\n",
        "    }\n",
        "  }\n",
        "}"
      ]
    }
  ]
}