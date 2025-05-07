import requests
from bs4 import BeautifulSoup
import os
import time

# 保存先ディレクトリ
OUTPUT_DIR = "../wikipedia_articles"
os.makedirs(OUTPUT_DIR, exist_ok=True)

# ランダム記事取得ループ
for i in range(1, 201):
    try:
        # Wikipediaランダム記事
        response = requests.get("https://en.wikipedia.org/wiki/Special:Random", allow_redirects=True, timeout=10)
        article_url = response.url
        print(f"{i}: {article_url}")

        # 内容取得と解析
        soup = BeautifulSoup(response.text, 'html.parser')

        # 本文を抽出
        content_div = soup.find("div", {"id": "bodyContent"})
        
        text = content_div.get_text()
        text = text.replace("\n"," ")
        # print(text)
        # ファイル保存
        filename = os.path.join(OUTPUT_DIR, f"{i}.txt")
        with open(filename, "w", encoding="utf-8") as f:
            f.write(text)

        # 優しめのアクセス間隔
        time.sleep(1)

    except Exception as e:
        print(f"Error fetching article {i}: {e}")
