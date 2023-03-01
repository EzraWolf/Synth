
import numpy as np

def sine(
    freq_hz: int,
    duration_sample: float = 1,
    volume: float = 1,
) -> None:
    if volume <= 0:
        raise Exception('Cannot have negative or 0 volume')

    np.sin()
    np.sin(np.pi)

def triangle() -> None:
    pass

def sawtooth() -> None:
    pass

def square() -> None:
    pass

def noise() -> None:
    pass
