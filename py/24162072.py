import pandas as pd

df = pd.read_tsv("chipotle.tsv")
print(df[(df["Price" >= 10)]
