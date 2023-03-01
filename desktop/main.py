
import pyaudio as pa

from desktop import config
from desktop import oscillator as osc

def main():
    
    frames = osc.sine(frequency, time)
    stream = audio.open(
        format=config.BIT_FORMAT,
        channels=config.CHANNEL_COUNT,
        rate=config.SAMPLE_RATE_KHz,
        output=True
    )
    stream.write(frames)
    stream.stop_stream()
    stream.close()

if __name__ == '__main__':
    audio = pa.PyAudio()
    main()
