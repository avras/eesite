--------------------------------------------------------------------------------
{-# LANGUAGE OverloadedStrings #-}
import           Data.Monoid (mappend)
import           Hakyll


--------------------------------------------------------------------------------
main :: IO ()
main = hakyll $ do
    match ("images/*" .||. "js/*" .||. "fonts/**") $ do
        route   idRoute
        compile copyFileCompiler

    match "css/*" $ do
        route   idRoute
        compile compressCssCompiler

    match (fromList [ "about.md"
                    , "courses.md"
                    , "links.md"
                    , "projects.md"
                    , "students.md"
                    , "bitcoin.md"
                    , "zk.md"
                    ]
          ) $ do
        route   $ setExtension "html"
        compile $ pandocCompiler
            >>= loadAndApplyTemplate "templates/default.html" defaultContext
            >>= relativizeUrls

    match ( "static/courses/**" .||.
            "static/bitcoin/**" .||.
            "static/monero/**" .||.
            "static/ethlab/**" .||.
            "static/zk/**" .||.
            "static/reports/**" .||.
            "static/ee1mtech/**"
          ) $ do
        route $ (gsubRoute "static/" (const ""))
        compile copyFileCompiler

    match ( "courses/EE706/*.html" .||.
            "courses/EE453717/*.html" .||.
            "courses/EE605/*.html" .||.
            "courses/EE703/*.html" .||.
            "courses/EE325/*.html"
          ) $ do
        route idRoute
        compile $ do
            getResourceBody
                >>= applyAsTemplate defaultContext
                >>= loadAndApplyTemplate "templates/default.html" defaultContext
                >>= relativizeUrls

    match (
            "courses/EE325/*.md" .||.
            "courses/EE703/*.md" .||.
            "courses/EE605/*.md" .||.
            "courses/EE720/*.md" .||.
            "courses/EE465/*.md" .||.
            "courses/cep/*.md"
          ) $ do
        route   $ setExtension "html"
        compile $ pandocCompiler
            >>= loadAndApplyTemplate "templates/default.html" defaultContext
            >>= relativizeUrls

    match "index.html" $ do
        route idRoute
        compile $ do
            getResourceBody
                >>= applyAsTemplate defaultContext
                >>= loadAndApplyTemplate "templates/default.html" defaultContext
                >>= relativizeUrls

    match "templates/*" $ compile templateCompiler
